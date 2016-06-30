// Copyright(c) 2001 arton
	
// midiOutCaps.h : CmidiOutCaps ÇÃêÈåæ

#ifndef __MIDIOUTCAPS_H_
#define __MIDIOUTCAPS_H_

#include "resource.h"       // ÉÅÉCÉì ÉVÉìÉ{Éã

/////////////////////////////////////////////////////////////////////////////
// CmidiOutCaps
class ATL_NO_VTABLE CmidiOutCaps : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CmidiOutCaps, &CLSID_midiOutCaps>,
	public ISupportErrorInfo,
	public IDispatchImpl<ImidiOutCaps, &IID_ImidiOutCaps, &LIBID_MIDICTLLib>
{
public:
	CmidiOutCaps() : m_lDevNum(-1)
	{
		m_pUnkMarshaler = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_MIDIOUTCAPS)
DECLARE_GET_CONTROLLING_UNKNOWN()

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CmidiOutCaps)
	COM_INTERFACE_ENTRY(ImidiOutCaps)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, m_pUnkMarshaler.p)
END_COM_MAP()

	HRESULT FinalConstruct()
	{
		return CoCreateFreeThreadedMarshaler(
			GetControllingUnknown(), &m_pUnkMarshaler.p);
	}

	void FinalRelease()
	{
		m_pUnkMarshaler.Release();
	}

	CComPtr<IUnknown> m_pUnkMarshaler;

	void InternalInitialize(long, MIDIOUTCAPS&);

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// ImidiOutCaps
public:
	HRESULT STDMETHODCALLTYPE get_ManufacturerID( 
            /* [retval][out] */ long __RPC_FAR *pResult);
        
	HRESULT STDMETHODCALLTYPE get_ProductID( 
            /* [retval][out] */ long __RPC_FAR *pResult);
        
	HRESULT STDMETHODCALLTYPE get_DriverMajorVersion( 
            /* [retval][out] */ long __RPC_FAR *pResult);
        
	HRESULT STDMETHODCALLTYPE get_DriverMinorVersion( 
            /* [retval][out] */ long __RPC_FAR *pResult);
        
	HRESULT STDMETHODCALLTYPE get_ProductName( 
            /* [retval][out] */ BSTR __RPC_FAR *pResult);
        
	HRESULT STDMETHODCALLTYPE get_Technology( 
            /* [retval][out] */ BSTR __RPC_FAR *pResult);
        
	HRESULT STDMETHODCALLTYPE get_Voices( 
            /* [retval][out] */ short __RPC_FAR *pResult);
        
	HRESULT STDMETHODCALLTYPE get_Notes( 
            /* [retval][out] */ short __RPC_FAR *pResult);
        
	HRESULT STDMETHODCALLTYPE get_ChannelMask( 
            /* [retval][out] */ short __RPC_FAR *pResult);
        
	HRESULT STDMETHODCALLTYPE get_Support( 
            /* [retval][out] */ long __RPC_FAR *pResult);
        
	HRESULT STDMETHODCALLTYPE get_Device( 
            /* [retval][out] */ ImidiOut __RPC_FAR *__RPC_FAR *ppResult);

private:
	MIDIOUTCAPS m_mop;
	long m_lDevNum;
};

#endif //__MIDIOUTCAPS_H_
