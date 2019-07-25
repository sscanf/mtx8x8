// Comm.h: interface for the CComm class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMM_H__5017E541_1762_11D2_A73D_0000E832DAC0__INCLUDED_)
#define AFX_COMM_H__5017E541_1762_11D2_A73D_0000E832DAC0__INCLUDED_

#if _MSC_VER >= 1000
#include "mtx8x8view.h"
#pragma once
#endif // _MSC_VER >= 1000

class CComm  
{
public:
	CComm();
	CComm(CString puerto, HWND hWnd);

	abrir (CString puerto, HWND hWnd);
	virtual ~CComm();
	void CommRx(unsigned char *msg, DWORD len);

public:
	DWORD TxBuff (char *buff, DWORD len);
	HANDLE hCom;
protected:
	HWND m_hWnd;
	CMtx8x8View *m_pDoc;
	UINT MsgOk;
};

#endif // !defined(AFX_COMM_H__5017E541_1762_11D2_A73D_0000E832DAC0__INCLUDED_)
