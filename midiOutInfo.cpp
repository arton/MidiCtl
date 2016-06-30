// Copyright(c) 2001 arton
// midiOutInfo.cpp : CmidiOutInfo のインプリメンテーション
#include "stdafx.h"
#include "MidiCtl.h"
#include "midiOutInfo.h"
#include "midiOutCaps.h"
#include "midiOut.h"

static HRESULT CreateOutCaps(int Index, ImidiOutCaps** pp, CmidiOutInfo* p)
{
	MIDIOUTCAPS moc;
	ZeroMemory(&moc, sizeof(moc));
	MMRESULT mr = midiOutGetDevCaps(Index, &moc, sizeof(moc));
	if (mr == MMSYSERR_BADDEVICEID)
	{
		return S_FALSE;
	}
	else if (mr == MMSYSERR_NOERROR)
	{
		CComObject<CmidiOutCaps>* p;
		HRESULT hr = CComObject<CmidiOutCaps>::CreateInstance(&p);
		if (hr == S_OK)
		{
			p->InternalInitialize(Index, moc);
			hr = p->QueryInterface(IID_ImidiOutCaps, (void**)pp);
		}
		return hr;
	}
	return (p) ? CreateError(mr, p) : MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, mr);
}

class CMOPEnum : public IEnumVARIANT
{
public:
	CMOPEnum(int DevNum)
		: m_ulRef(1), m_iIndex(0), m_iDevNum(DevNum)
	{
	}
	~CMOPEnum()
	{
	}
	STDMETHOD_(ULONG, AddRef)()
	{
		return ++m_ulRef;
	}
	STDMETHOD_(ULONG, Release)()
	{
		m_ulRef--;
		if (m_ulRef <= 0)
		{
			delete this;
			return 0;
		}
		return m_ulRef;
	}
	STDMETHOD(QueryInterface)(REFIID iid, void ** ppvObject)
	{
		if (!ppvObject) return E_POINTER;
		if (IsEqualIID(IID_IUnknown, iid) 
			|| IsEqualIID(IID_IEnumVARIANT, iid)) {
			*ppvObject = this;
			m_ulRef++;
			return S_OK;
		}
		return E_NOINTERFACE;
	}

    HRESULT STDMETHODCALLTYPE Next(
		ULONG cElements, 
		VARIANT FAR* pvar, 
		ULONG FAR* pcElementFetched)
	{
		if (m_iIndex >= m_iDevNum) return S_FALSE;

		ULONG l2;
		if (pcElementFetched != NULL)        
			*pcElementFetched = 0;
		for (ULONG l=0; l<cElements; l++)        
			VariantInit(&pvar[l]);
		// Retrieve the next cElements elements.
		for (l2 = 0; m_iIndex < m_iDevNum && l2 < cElements; l2++, m_iIndex++)
		{
			ImidiOutCaps* p;
			HRESULT hr = CreateOutCaps(m_iIndex, &p, NULL);
			if (hr != S_OK)
				break;
			pvar[l2].pdispVal = p;
			pvar[l2].vt = VT_DISPATCH;
		}    
		// Set count of elements retrieved.
		if (pcElementFetched != NULL)        
			*pcElementFetched = l2;
		return  (l2 < cElements) ? S_FALSE : S_OK;
	}
    HRESULT STDMETHODCALLTYPE Skip(unsigned long celt)
	{
		while (celt)
		{
			if (m_iIndex > m_iDevNum) return S_FALSE;
			celt--;
			m_iIndex++;
		}
		return S_OK;
	}
    HRESULT STDMETHODCALLTYPE Reset()
	{
		m_iIndex = 0;
		return S_OK;
	}
    HRESULT STDMETHODCALLTYPE Clone(IEnumVARIANT FAR* FAR* ppenum)
	{
		if (!ppenum) return E_POINTER;
		*ppenum = new CMOPEnum(m_iDevNum);
		return S_OK;
	}
private:
	ULONG m_ulRef;
	int m_iIndex, m_iDevNum;
};


/////////////////////////////////////////////////////////////////////////////
// CmidiOutInfo
HRESULT STDMETHODCALLTYPE CmidiOutInfo::get_Length( 
            /* [retval][out] */ long __RPC_FAR *pResult)
{
	if (!pResult) return E_POINTER;
	*pResult = midiOutGetNumDevs();
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE CmidiOutInfo::get__NewEnum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk)
{
	if (!ppUnk) return E_POINTER;
	*ppUnk = new CMOPEnum(midiOutGetNumDevs());
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE CmidiOutInfo::get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ ImidiOutCaps __RPC_FAR *__RPC_FAR *ppCaps)
{
	if (!ppCaps) return E_POINTER;
	*ppCaps = NULL;
	return CreateOutCaps(Index, ppCaps, this);
}

HRESULT STDMETHODCALLTYPE CmidiOutInfo::get_Mapper( 
            /* [retval][out] */ ImidiOut __RPC_FAR *__RPC_FAR *ppResult)
{
	if (!ppResult) return E_POINTER;
	*ppResult = NULL;
	CComObject<CmidiOut>* p;
	HRESULT hr = CComObject<CmidiOut>::CreateInstance(&p);
	if (hr == S_OK)
	{
		MMRESULT mr = p->Open(MIDI_MAPPER);
		if (mr == MMSYSERR_NOERROR)
		{
			hr = p->QueryInterface(IID_ImidiOut, (void**)ppResult);
		}
		else
		{
			hr = CreateError(mr, this);
			delete p;
		}
	}
	return hr;
}

HRESULT STDMETHODCALLTYPE CmidiOutInfo::get_TimerResolution( 
            /* [retval][out] */ long __RPC_FAR *pResult)
{
	if (!pResult) return E_POINTER;

	TIMECAPS tc;
	MMRESULT mr = timeGetDevCaps(&tc, sizeof(TIMECAPS));
	if (mr != TIMERR_NOERROR) 
	{
		return CreateError(mr, this);
    }
	m_uiResolution = min(max(tc.wPeriodMin, 1), tc.wPeriodMax);
	mr = timeBeginPeriod(m_uiResolution);
	*pResult = m_uiResolution;
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE CmidiOutInfo::Wait( 
            /* [in] */ long WaitVal,
            /* [in] */ long Resolution)
{
	if (!WaitVal) return S_OK;

	if (m_hTimer == NULL)
	{
		m_hTimer = CreateEvent(NULL, FALSE, FALSE, NULL);
	}
	MMRESULT mr = timeSetEvent(WaitVal, Resolution, (LPTIMECALLBACK)m_hTimer,
		0, TIME_CALLBACK_EVENT_SET);
	if (mr != NULL)
	{
		for (;;)
		{
			MSG msg;
			while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				if (msg.message == WM_QUIT) break;
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			DWORD dw = MsgWaitForMultipleObjects(1, &m_hTimer, FALSE, 60000, QS_ALLINPUT);
			if (dw == WAIT_TIMEOUT)
			{
				ATLTRACE(_T("timeSet(%d, %d) Failed2 %d\n"), WaitVal, Resolution, GetLastError());
				timeKillEvent(mr);
			}
			else if (dw == WAIT_OBJECT_0)
			{
				ATLTRACE(_T("timeSet(%d, %d) succ %d\n"), WaitVal, Resolution, GetLastError());
				break;
			}
		}
	}
	else
	{
		ATLTRACE(_T("timeSet(%d, %d) Failed %d\n"), WaitVal, Resolution, GetLastError());
		Sleep(WaitVal);
	}
	return S_OK;
}

void CmidiOutInfo::FinalRelease()
{
	if (m_uiResolution)
		timeKillEvent(m_uiResolution);
	if (m_hTimer)
		CloseHandle(m_hTimer);
	m_pUnkMarshaler.Release();
}

STDMETHODIMP CmidiOutInfo::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_ImidiOutInfo
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}
