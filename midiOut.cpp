// Copyright(c) 2001 arton
// midiOut.cpp : CmidiOut のインプリメンテーション
#include "stdafx.h"
#include "MidiCtl.h"
#include "midiOut.h"

/////////////////////////////////////////////////////////////////////////////
// CmidiOut
HRESULT CmidiOut::FinalConstruct()
{
	m_hMIDI = (HMIDIOUT)INVALID_HANDLE_VALUE;
	return S_OK;
}

void CmidiOut::FinalRelease()
{
	if (m_hMIDI != (HMIDIOUT)INVALID_HANDLE_VALUE)
	{
		Close();
	}
}

MMRESULT CmidiOut::Open(long DevNum)
{
	UINT u = midiOutOpen(&m_hMIDI, DevNum, NULL, NULL, CALLBACK_NULL);
	return u;
}

HRESULT STDMETHODCALLTYPE CmidiOut::Close( void)
{
	HRESULT hr = S_OK;
	int cb(0);
	if (m_hMIDI != (HMIDIOUT)INVALID_HANDLE_VALUE)
	{
		do
		{
			hr = midiOutClose(m_hMIDI);
			if (hr == MIDIERR_STILLPLAYING)
			{
				midiOutReset(m_hMIDI);
			}
			else if (hr != MMSYSERR_NOERROR)
			{
				Sleep(100);
				cb++;
			}
		}
		while (hr != MMSYSERR_NOERROR && cb < 8);
		m_hMIDI = (HMIDIOUT)INVALID_HANDLE_VALUE;
	}
	return hr;
}
        
HRESULT STDMETHODCALLTYPE CmidiOut::Send( 
            /* [in] */ long Msg)
{
	if (m_hMIDI == (HMIDIOUT)INVALID_HANDLE_VALUE) return Error(IDS_E_NOTOPENED);
	MMRESULT hr;
	if ((Msg & 0xff) == m_bLastStat)
	{
		hr = midiOutShortMsg(m_hMIDI, Msg >> 8);
	}
	else
	{
		hr = midiOutShortMsg(m_hMIDI, Msg);
		m_bLastStat = (BYTE)Msg;
	}
	if (hr != MMSYSERR_NOERROR)
	{
		return CreateError(hr, this);
	}
	return (HRESULT)hr;
}

HRESULT STDMETHODCALLTYPE CmidiOut::get_Volume( 
            /* [retval][out] */ long __RPC_FAR *pResult)
{
	if (!pResult) return E_POINTER;
	if (m_hMIDI == (HMIDIOUT)INVALID_HANDLE_VALUE) return Error(IDS_E_NOTOPENED);

	MMRESULT hr = midiOutGetVolume(m_hMIDI, reinterpret_cast<DWORD*>(pResult));
	if (hr != MMSYSERR_NOERROR)
		return CreateError(hr, this);

	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE CmidiOut::put_Volume( 
            /* [in] */ long NewVal)
{
	if (m_hMIDI == (HMIDIOUT)INVALID_HANDLE_VALUE) return Error(IDS_E_NOTOPENED);

	MMRESULT hr = midiOutSetVolume(m_hMIDI, NewVal);
	if (hr != MMSYSERR_NOERROR)
		return CreateError(hr, this);

	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE CmidiOut::Reset( void)
{
	if (m_hMIDI == (HMIDIOUT)INVALID_HANDLE_VALUE) return Error(IDS_E_NOTOPENED);

	MMRESULT hr = midiOutReset(m_hMIDI);
	if (hr != MMSYSERR_NOERROR)
		return CreateError(hr, this);

	return S_OK;
}

STDMETHODIMP CmidiOut::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_ImidiOut
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}
