// stdafx.h : �W���̃V�X�e�� �C���N���[�h �t�@�C���A
//            �܂��͎Q�Ɖ񐔂������A�����܂�ύX����Ȃ�
//            �v���W�F�N�g��p�̃C���N���[�h �t�@�C�����L�q���܂��B

#if !defined(AFX_STDAFX_H__E6ABEB39_D9FF_4116_8BA0_F06321D2530D__INCLUDED_)
#define AFX_STDAFX_H__E6ABEB39_D9FF_4116_8BA0_F06321D2530D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define STRICT
#define _ATL_APARTMENT_THREADED

#include <atlbase.h>
// CComModule �N���X����h�������N���X���g�p���āA�I�[�o�[���C�h����ꍇ
// _Module �̖��O�͕ύX���Ȃ��ł��������B
extern CComModule _Module;
#include <atlcom.h>
#include <atlctl.h>
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B
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
