// mtx8x8.h : main header file for the MTX8X8 application
//

#if !defined(AFX_MTX8X8_H__5BF27797_2144_11D2_A74D_0000E832DAC0__INCLUDED_)
#define AFX_MTX8X8_H__5BF27797_2144_11D2_A74D_0000E832DAC0__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMtx8x8App:
// See mtx8x8.cpp for the implementation of this class
//

class CMtx8x8App : public CWinApp
{
public:
	CMtx8x8App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMtx8x8App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMtx8x8App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MTX8X8_H__5BF27797_2144_11D2_A74D_0000E832DAC0__INCLUDED_)
