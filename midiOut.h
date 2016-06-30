// Copyright(c) 2001 arton

// midiOut.h : CmidiOut ÇÃêÈåæ

#ifndef __MIDIOUT_H_
#define __MIDIOUT_H_

#include "resource.h"       // ÉÅÉCÉì ÉVÉìÉ{Éã

/////////////////////////////////////////////////////////////////////////////
// CmidiOut
class ATL_NO_VTABLE CmidiOut : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CmidiOut, &CLSID_midiOut>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CmidiOut>,
	public IDispatchImpl<ImidiOut, &IID_ImidiOut, &LIBID_MIDICTLLib>,
	public IObjectSafetyImpl<CmidiOut, INTERFACESAFE_FOR_UNTRUSTED_DATA>
{
public:
	CmidiOut() :
	  m_bLastStat(0)
	{
	}

	
DECLARE_REGISTRY_RESOURCEID(IDR_MIDIOUT)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CmidiOut)
	COM_INTERFACE_ENTRY(ImidiOut)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(IObjectSafety)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CmidiOut)
END_CONNECTION_POINT_MAP()

	HRESULT FinalConstruct();
	void FinalRelease();
	MMRESULT Open(long);

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// ImidiOut
public:
	HRESULT STDMETHODCALLTYPE Close( void);
        
	HRESULT STDMETHODCALLTYPE Send( 
            /* [in] */ long Msg);

	HRESULT STDMETHODCALLTYPE get_Volume( 
            /* [retval][out] */ long __RPC_FAR *pResult);
        
	HRESULT STDMETHODCALLTYPE put_Volume( 
            /* [in] */ long NewVal);
        
	HRESULT STDMETHODCALLTYPE Reset( void);
private:
	BYTE m_bLastStat;
	HMIDIOUT m_hMIDI;
};

#endif //__MIDIOUT_H_
