

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_MIDICTLLib,0x2161E819,0xCC11,0x4FDD,0x8A,0x2D,0x75,0x99,0xD7,0x91,0x46,0x5A);


MIDL_DEFINE_GUID(IID, IID_ImidiOut,0x2B1D37CF,0x9051,0x4811,0x85,0x88,0xFF,0x6A,0xF7,0xEF,0x81,0xAE);


MIDL_DEFINE_GUID(IID, DIID__ImidiOutEvents,0x9E6212AE,0x7995,0x4342,0xB4,0x7E,0xD5,0x19,0xFB,0x48,0xC3,0xCF);


MIDL_DEFINE_GUID(IID, IID_ImidiOutCaps,0x9503B5DD,0x503A,0x48FE,0xBC,0x80,0xCE,0x1C,0x19,0x5E,0x09,0x51);


MIDL_DEFINE_GUID(IID, IID_ImidiOutInfo,0x0C251B6D,0x5B53,0x4E51,0x93,0x84,0x04,0x63,0xA4,0x50,0xAC,0x01);


MIDL_DEFINE_GUID(CLSID, CLSID_midiOut,0x6ABCDF21,0x91CE,0x4D73,0x82,0x0D,0xC3,0xCB,0x6D,0x27,0xC2,0x36);


MIDL_DEFINE_GUID(CLSID, CLSID_midiOutInfo,0x4BEBEFDB,0x45CC,0x47C2,0xB6,0x58,0x91,0x5E,0x7D,0x00,0x25,0x64);


MIDL_DEFINE_GUID(CLSID, CLSID_midiOutCaps,0xD103AB12,0xEFA3,0x4942,0xAA,0x6D,0x70,0xC3,0x49,0x0D,0x0F,0x44);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



