// stdafx.h : 標準のシステム インクルード ファイル、
//            または参照回数が多く、かつあまり変更されない
//            プロジェクト専用のインクルード ファイルを記述します。

#if !defined(AFX_STDAFX_H__E6ABEB39_D9FF_4116_8BA0_F06321D2530D__INCLUDED_)
#define AFX_STDAFX_H__E6ABEB39_D9FF_4116_8BA0_F06321D2530D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define STRICT
#define _ATL_APARTMENT_THREADED

#include <atlbase.h>
// CComModule クラスから派生したクラスを使用して、オーバーライドする場合
// _Module の名前は変更しないでください。
extern CComModule _Module;
#include <atlcom.h>
#include <atlctl.h>
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。
#include <mmsystem.h>
template< class T >
HRESULT CreateError(MMRESULT mr, T* p)
{
	TCHAR sz[MAXERRORLENGTH];
	if (midiOutGetErrorText(mr, sz, MAXERRORLENGTH) == MMSYSERR_NOERROR)
		return p->Error(sz, GUID_NULL, MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, mr));
	return (HRESULT)mr;
}

#endif // !defined(AFX_STDAFX_H__E6ABEB39_D9FF_4116_8BA0_F06321D2530D__INCLUDED)
