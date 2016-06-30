// Copyright(c) 2001 arton
// midiOutCaps.cpp : CmidiOutCaps のインプリメンテーション
#include "stdafx.h"
#include "MidiCtl.h"
#include "midiOutCaps.h"
#include "midiOut.h"

/////////////////////////////////////////////////////////////////////////////
// CmidiOutCaps
void CmidiOutCaps::InternalInitialize(long did, MIDIOUTCAPS& mop)
{
	m_lDevNum = did;
	m_mop = mop;
}

HRESULT STDMETHODCALLTYPE CmidiOutCaps::get_ManufacturerID( 
            /* [retval][out] */ long __RPC_FAR *pResult)
{
	if (!pResult) return E_POINTER;
	*pResult = m_mop.wMid;
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE CmidiOutCaps::get_ProductID( 
            /* [retval][out] */ long __RPC_FAR *pResult)
{
	if (!pResult) return E_POINTER;
	*pResult = m_mop.wPid;
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE CmidiOutCaps::get_DriverMajorVersion( 
            /* [retval][out] */ long __RPC_FAR *pResult)
{
	if (!pResult) return E_POINTER;
	*pResult = (BYTE)(m_mop.vDriverVersion >> 8);
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE CmidiOutCaps::get_DriverMinorVersion( 
            /* [retval][out] */ long __RPC_FAR *pResult)
{
	if (!pResult) return E_POINTER;
	*pResult = (BYTE)m_mop.vDriverVersion;
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE CmidiOutCaps::get_ProductName( 
            /* [retval][out] */ BSTR __RPC_FAR *pResult)
{
	if (!pResult) return E_POINTER;
	USES_CONVERSION;
	*pResult = SysAllocString(T2OLE(m_mop.szPname));
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE CmidiOutCaps::get_Technology( 
            /* [retval][out] */ BSTR __RPC_FAR *pResult)
{
	if (!pResult) return E_POINTER;
	// this matter is fastest, but I like lookup table more...
	switch (m_mop.wTechnology)
	{
	case MOD_MIDIPORT:
		*pResult = SysAllocString(L"MIDI hardware port");
		break;
	case MOD_SYNTH:
		*pResult = SysAllocString(L"synthesizer");
		break;
	case MOD_SQSYNTH:
		*pResult = SysAllocString(L"square wave synthesizer");
		break;
	case MOD_FMSYNTH:
		*pResult = SysAllocString(L"FM synthesizer");
		break;
	case MOD_MAPPER:
		*pResult = SysAllocString(L"the Microsoft MIDI mapper");
		break;
	case MOD_WAVETABLE:
		*pResult = SysAllocString(L"hardware wavetable synthesizer");
		break;
	case MOD_SWSYNTH:
		*pResult = SysAllocString(L"software synthesizer");
		break;
	default:
		*pResult = SysAllocString(L"Unknown");
		break;
	}
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE CmidiOutCaps::get_Voices( 
            /* [retval][out] */ short __RPC_FAR *pResult)
{
	if (!pResult) return E_POINTER;
	*pResult = m_mop.wVoices;
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE CmidiOutCaps::get_Notes( 
            /* [retval][out] */ short __RPC_FAR *pResult)
{
	if (!pResult) return E_POINTER;
	*pResult = m_mop.wNotes;
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE CmidiOutCaps::get_ChannelMask( 
            /* [retval][out] */ short __RPC_FAR *pResult)
{
	if (!pResult) return E_POINTER;
	*pResult = m_mop.wChannelMask;
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE CmidiOutCaps::get_Support( 
            /* [retval][out] */ long __RPC_FAR *pResult)
{
	if (!pResult) return E_POINTER;
	*pResult = m_mop.dwSupport;
	return S_OK;
}
        
HRESULT STDMETHODCALLTYPE CmidiOutCaps::get_Device( 
            /* [retval][out] */ ImidiOut __RPC_FAR *__RPC_FAR *ppResult)
{
	if (!ppResult) return E_POINTER;
	*ppResult = NULL;
	CComObject<CmidiOut>* p;
	HRESULT hr = CComObject<CmidiOut>::CreateInstance(&p);
	if (hr == S_OK)
	{
		MMRESULT mr = p->Open(m_lDevNum);
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

STDMETHODIMP CmidiOutCaps::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_ImidiOutCaps
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}
