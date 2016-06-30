// Copyright(c) 2001 arton
	
// midiOutInfo.h : CmidiOutInfo ÇÃêÈåæ

#ifndef __MIDIOUTINFO_H_
#define __MIDIOUTINFO_H_

#include "resource.h"       // ÉÅÉCÉì ÉVÉìÉ{Éã

/////////////////////////////////////////////////////////////////////////////
// CmidiOutInfo
class ATL_NO_VTABLE CmidiOutInfo : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CmidiOutInfo, &CLSID_midiOutInfo>,
	public ISupportErrorInfo,
	public IDispatchImpl<ImidiOutInfo, &IID_ImidiOutInfo, &LIBID_MIDICTLLib>,
	public IObjectSafetyImpl<CmidiOutInfo, INTERFACESAFE_FOR_UNTRUSTED_DATA>
{
public:
	CmidiOutInfo() :
	  m_hTimer(NULL), m_uiResolution(0)
	{
		m_pUnkMarshaler = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_MIDIOUTINFO)
DECLARE_GET_CONTROLLING_UNKNOWN()

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CmidiOutInfo)
	COM_INTERFACE_ENTRY(ImidiOutInfo)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IObjectSafety)
	COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, m_pUnkMarshaler.p)
END_COM_MAP()

	HRESULT FinalConstruct()
	{
		return CoCreateFreeThreadedMarshaler(
			GetControllingUnknown(), &m_pUnkMarshaler.p);
	}

	void FinalRelease();

	CComPtr<IUnknown> m_pUnkMarshaler;

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// ImidiOutInfo
public:
	HRESULT STDMETHODCALLTYPE get_Length( 
            /* [retval][out] */ long __RPC_FAR *pResult);
        
	HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppUnk);
        
	HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ ImidiOutCaps __RPC_FAR *__RPC_FAR *ppCaps);

	HRESULT STDMETHODCALLTYPE get_Mapper( 
            /* [retval][out] */ ImidiOut __RPC_FAR *__RPC_FAR *ppResult);

	HRESULT STDMETHODCALLTYPE get_TimerResolution( 
            /* [retval][out] */ long __RPC_FAR *pResult);
        
	HRESULT STDMETHODCALLTYPE Wait( 
            /* [in] */ long WaitVal,
            /* [in] */ long Resolution);

private:
	HANDLE m_hTimer;
	UINT m_uiResolution;
};

#endif //__MIDIOUTINFO_H_
