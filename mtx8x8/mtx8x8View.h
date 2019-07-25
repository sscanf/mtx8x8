// mtx8x8View.h : interface of the CMtx8x8View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MTX8X8VIEW_H__5BF2779F_2144_11D2_A74D_0000E832DAC0__INCLUDED_)
#define AFX_MTX8X8VIEW_H__5BF2779F_2144_11D2_A74D_0000E832DAC0__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "mtx8x8doc.h"

class CComm;
class CMtx8x8View : public CFormView
{
protected: // create from serialization only
	CMtx8x8View();
	DECLARE_DYNCREATE(CMtx8x8View)

public:
	//{{AFX_DATA(CMtx8x8View)
	enum { IDD = IDD_MTX8X8_FORM };
	CSpinButtonCtrl	m_BudRead;
	CSpinButtonCtrl	m_BudWrite;
	UINT	m_EntradaTx;
	UINT	m_EntradaRx;
	BOOL	m_salida1;
	BOOL	m_salida2;
	BOOL	m_salida3;
	BOOL	m_salida4;
	BOOL	m_salida5;
	BOOL	m_salida6;
	BOOL	m_salida7;
	BOOL	m_salida8;
	//}}AFX_DATA

// Attributes
public:
	CMtx8x8Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMtx8x8View)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMtx8x8View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	UCHAR m_bEntradaTx;
	UCHAR m_bSalidaTx;
	CComm *m_pCom;
	//{{AFX_MSG(CMtx8x8View)
	afx_msg void OnEscribir();
	afx_msg void OnRxStatus (WPARAM, LPARAM);
	afx_msg void OnLeer();
	afx_msg void OnBorrar();
	afx_msg void OnActivar();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in mtx8x8View.cpp
inline CMtx8x8Doc* CMtx8x8View::GetDocument()
   { return (CMtx8x8Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MTX8X8VIEW_H__5BF2779F_2144_11D2_A74D_0000E832DAC0__INCLUDED_)
