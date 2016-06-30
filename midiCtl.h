

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Fri Jul 01 00:22:07 2016
 */
/* Compiler settings for midiCtl.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __midiCtl_h__
#define __midiCtl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ImidiOut_FWD_DEFINED__
#define __ImidiOut_FWD_DEFINED__
typedef interface ImidiOut ImidiOut;

#endif 	/* __ImidiOut_FWD_DEFINED__ */


#ifndef ___ImidiOutEvents_FWD_DEFINED__
#define ___ImidiOutEvents_FWD_DEFINED__
typedef interface _ImidiOutEvents _ImidiOutEvents;

#endif 	/* ___ImidiOutEvents_FWD_DEFINED__ */


#ifndef __ImidiOutCaps_FWD_DEFINED__
#define __ImidiOutCaps_FWD_DEFINED__
typedef interface ImidiOutCaps ImidiOutCaps;

#endif 	/* __ImidiOutCaps_FWD_DEFINED__ */


#ifndef __ImidiOutInfo_FWD_DEFINED__
#define __ImidiOutInfo_FWD_DEFINED__
typedef interface ImidiOutInfo ImidiOutInfo;

#endif 	/* __ImidiOutInfo_FWD_DEFINED__ */


#ifndef __midiOut_FWD_DEFINED__
#define __midiOut_FWD_DEFINED__

#ifdef __cplusplus
typedef class midiOut midiOut;
#else
typedef struct midiOut midiOut;
#endif /* __cplusplus */

#endif 	/* __midiOut_FWD_DEFINED__ */


#ifndef __midiOutInfo_FWD_DEFINED__
#define __midiOutInfo_FWD_DEFINED__

#ifdef __cplusplus
typedef class midiOutInfo midiOutInfo;
#else
typedef struct midiOutInfo midiOutInfo;
#endif /* __cplusplus */

#endif 	/* __midiOutInfo_FWD_DEFINED__ */


#ifndef __midiOutCaps_FWD_DEFINED__
#define __midiOutCaps_FWD_DEFINED__

#ifdef __cplusplus
typedef class midiOutCaps midiOutCaps;
#else
typedef struct midiOutCaps midiOutCaps;
#endif /* __cplusplus */

#endif 	/* __midiOutCaps_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __MIDICTLLib_LIBRARY_DEFINED__
#define __MIDICTLLib_LIBRARY_DEFINED__

/* library MIDICTLLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_MIDICTLLib;

#ifndef __ImidiOut_INTERFACE_DEFINED__
#define __ImidiOut_INTERFACE_DEFINED__

/* interface ImidiOut */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ImidiOut;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2B1D37CF-9051-4811-8588-FF6AF7EF81AE")
    ImidiOut : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Send( 
            /* [in] */ long Msg) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Volume( 
            /* [retval][out] */ long *pResult) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Volume( 
            /* [in] */ long NewVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ImidiOutVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ImidiOut * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ImidiOut * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ImidiOut * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ImidiOut * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ImidiOut * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ImidiOut * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ImidiOut * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            ImidiOut * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Send )( 
            ImidiOut * This,
            /* [in] */ long Msg);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Volume )( 
            ImidiOut * This,
            /* [retval][out] */ long *pResult);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Volume )( 
            ImidiOut * This,
            /* [in] */ long NewVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Reset )( 
            ImidiOut * This);
        
        END_INTERFACE
    } ImidiOutVtbl;

    interface ImidiOut
    {
        CONST_VTBL struct ImidiOutVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ImidiOut_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ImidiOut_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ImidiOut_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ImidiOut_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ImidiOut_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ImidiOut_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ImidiOut_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ImidiOut_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define ImidiOut_Send(This,Msg)	\
    ( (This)->lpVtbl -> Send(This,Msg) ) 

#define ImidiOut_get_Volume(This,pResult)	\
    ( (This)->lpVtbl -> get_Volume(This,pResult) ) 

#define ImidiOut_put_Volume(This,NewVal)	\
    ( (This)->lpVtbl -> put_Volume(This,NewVal) ) 

#define ImidiOut_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ImidiOut_INTERFACE_DEFINED__ */


#ifndef ___ImidiOutEvents_DISPINTERFACE_DEFINED__
#define ___ImidiOutEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ImidiOutEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__ImidiOutEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("9E6212AE-7995-4342-B47E-D519FB48C3CF")
    _ImidiOutEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ImidiOutEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _ImidiOutEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _ImidiOutEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _ImidiOutEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _ImidiOutEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _ImidiOutEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _ImidiOutEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _ImidiOutEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _ImidiOutEventsVtbl;

    interface _ImidiOutEvents
    {
        CONST_VTBL struct _ImidiOutEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ImidiOutEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _ImidiOutEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _ImidiOutEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _ImidiOutEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _ImidiOutEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _ImidiOutEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _ImidiOutEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ImidiOutEvents_DISPINTERFACE_DEFINED__ */


#ifndef __ImidiOutCaps_INTERFACE_DEFINED__
#define __ImidiOutCaps_INTERFACE_DEFINED__

/* interface ImidiOutCaps */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ImidiOutCaps;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9503B5DD-503A-48FE-BC80-CE1C195E0951")
    ImidiOutCaps : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ManufacturerID( 
            /* [retval][out] */ long *pResult) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ProductID( 
            /* [retval][out] */ long *pResult) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_DriverMajorVersion( 
            /* [retval][out] */ long *pResult) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_DriverMinorVersion( 
            /* [retval][out] */ long *pResult) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ProductName( 
            /* [retval][out] */ BSTR *pResult) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Technology( 
            /* [retval][out] */ BSTR *pResult) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Voices( 
            /* [retval][out] */ short *pResult) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Notes( 
            /* [retval][out] */ short *pResult) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ChannelMask( 
            /* [retval][out] */ short *pResult) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Support( 
            /* [retval][out] */ long *pResult) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Device( 
            /* [retval][out] */ ImidiOut **ppResult) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ImidiOutCapsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ImidiOutCaps * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ImidiOutCaps * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ImidiOutCaps * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ImidiOutCaps * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ImidiOutCaps * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ImidiOutCaps * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ImidiOutCaps * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ManufacturerID )( 
            ImidiOutCaps * This,
            /* [retval][out] */ long *pResult);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ProductID )( 
            ImidiOutCaps * This,
            /* [retval][out] */ long *pResult);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DriverMajorVersion )( 
            ImidiOutCaps * This,
            /* [retval][out] */ long *pResult);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DriverMinorVersion )( 
            ImidiOutCaps * This,
            /* [retval][out] */ long *pResult);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ProductName )( 
            ImidiOutCaps * This,
            /* [retval][out] */ BSTR *pResult);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Technology )( 
            ImidiOutCaps * This,
            /* [retval][out] */ BSTR *pResult);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Voices )( 
            ImidiOutCaps * This,
            /* [retval][out] */ short *pResult);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Notes )( 
            ImidiOutCaps * This,
            /* [retval][out] */ short *pResult);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ChannelMask )( 
            ImidiOutCaps * This,
            /* [retval][out] */ short *pResult);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Support )( 
            ImidiOutCaps * This,
            /* [retval][out] */ long *pResult);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Device )( 
            ImidiOutCaps * This,
            /* [retval][out] */ ImidiOut **ppResult);
        
        END_INTERFACE
    } ImidiOutCapsVtbl;

    interface ImidiOutCaps
    {
        CONST_VTBL struct ImidiOutCapsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ImidiOutCaps_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ImidiOutCaps_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ImidiOutCaps_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ImidiOutCaps_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ImidiOutCaps_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ImidiOutCaps_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ImidiOutCaps_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ImidiOutCaps_get_ManufacturerID(This,pResult)	\
    ( (This)->lpVtbl -> get_ManufacturerID(This,pResult) ) 

#define ImidiOutCaps_get_ProductID(This,pResult)	\
    ( (This)->lpVtbl -> get_ProductID(This,pResult) ) 

#define ImidiOutCaps_get_DriverMajorVersion(This,pResult)	\
    ( (This)->lpVtbl -> get_DriverMajorVersion(This,pResult) ) 

#define ImidiOutCaps_get_DriverMinorVersion(This,pResult)	\
    ( (This)->lpVtbl -> get_DriverMinorVersion(This,pResult) ) 

#define ImidiOutCaps_get_ProductName(This,pResult)	\
    ( (This)->lpVtbl -> get_ProductName(This,pResult) ) 

#define ImidiOutCaps_get_Technology(This,pResult)	\
    ( (This)->lpVtbl -> get_Technology(This,pResult) ) 

#define ImidiOutCaps_get_Voices(This,pResult)	\
    ( (This)->lpVtbl -> get_Voices(This,pResult) ) 

#define ImidiOutCaps_get_Notes(This,pResult)	\
    ( (This)->lpVtbl -> get_Notes(This,pResult) ) 

#define ImidiOutCaps_get_ChannelMask(This,pResult)	\
    ( (This)->lpVtbl -> get_ChannelMask(This,pResult) ) 

#define ImidiOutCaps_get_Support(This,pResult)	\
    ( (This)->lpVtbl -> get_Support(This,pResult) ) 

#define ImidiOutCaps_get_Device(This,ppResult)	\
    ( (This)->lpVtbl -> get_Device(This,ppResult) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ImidiOutCaps_INTERFACE_DEFINED__ */


#ifndef __ImidiOutInfo_INTERFACE_DEFINED__
#define __ImidiOutInfo_INTERFACE_DEFINED__

/* interface ImidiOutInfo */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ImidiOutInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0C251B6D-5B53-4E51-9384-0463A450AC01")
    ImidiOutInfo : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Length( 
            /* [retval][out] */ long *pResult) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **ppUnk) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ ImidiOutCaps **ppCaps) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Mapper( 
            /* [retval][out] */ ImidiOut **ppResult) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_TimerResolution( 
            /* [retval][out] */ long *pResult) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Wait( 
            /* [in] */ long WaitVal,
            /* [in] */ long Resolution) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ImidiOutInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ImidiOutInfo * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ImidiOutInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ImidiOutInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ImidiOutInfo * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ImidiOutInfo * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ImidiOutInfo * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ImidiOutInfo * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Length )( 
            ImidiOutInfo * This,
            /* [retval][out] */ long *pResult);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            ImidiOutInfo * This,
            /* [retval][out] */ IUnknown **ppUnk);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            ImidiOutInfo * This,
            /* [in] */ long Index,
            /* [retval][out] */ ImidiOutCaps **ppCaps);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Mapper )( 
            ImidiOutInfo * This,
            /* [retval][out] */ ImidiOut **ppResult);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TimerResolution )( 
            ImidiOutInfo * This,
            /* [retval][out] */ long *pResult);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Wait )( 
            ImidiOutInfo * This,
            /* [in] */ long WaitVal,
            /* [in] */ long Resolution);
        
        END_INTERFACE
    } ImidiOutInfoVtbl;

    interface ImidiOutInfo
    {
        CONST_VTBL struct ImidiOutInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ImidiOutInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ImidiOutInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ImidiOutInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ImidiOutInfo_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ImidiOutInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ImidiOutInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ImidiOutInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ImidiOutInfo_get_Length(This,pResult)	\
    ( (This)->lpVtbl -> get_Length(This,pResult) ) 

#define ImidiOutInfo_get__NewEnum(This,ppUnk)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppUnk) ) 

#define ImidiOutInfo_get_Item(This,Index,ppCaps)	\
    ( (This)->lpVtbl -> get_Item(This,Index,ppCaps) ) 

#define ImidiOutInfo_get_Mapper(This,ppResult)	\
    ( (This)->lpVtbl -> get_Mapper(This,ppResult) ) 

#define ImidiOutInfo_get_TimerResolution(This,pResult)	\
    ( (This)->lpVtbl -> get_TimerResolution(This,pResult) ) 

#define ImidiOutInfo_Wait(This,WaitVal,Resolution)	\
    ( (This)->lpVtbl -> Wait(This,WaitVal,Resolution) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ImidiOutInfo_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_midiOut;

#ifdef __cplusplus

class DECLSPEC_UUID("6ABCDF21-91CE-4D73-820D-C3CB6D27C236")
midiOut;
#endif

EXTERN_C const CLSID CLSID_midiOutInfo;

#ifdef __cplusplus

class DECLSPEC_UUID("4BEBEFDB-45CC-47C2-B658-915E7D002564")
midiOutInfo;
#endif

EXTERN_C const CLSID CLSID_midiOutCaps;

#ifdef __cplusplus

class DECLSPEC_UUID("D103AB12-EFA3-4942-AA6D-70C3490D0F44")
midiOutCaps;
#endif
#endif /* __MIDICTLLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


