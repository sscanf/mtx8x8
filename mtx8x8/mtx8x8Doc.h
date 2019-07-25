// mtx8x8Doc.h : interface of the CMtx8x8Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MTX8X8DOC_H__5BF2779D_2144_11D2_A74D_0000E832DAC0__INCLUDED_)
#define AFX_MTX8X8DOC_H__5BF2779D_2144_11D2_A74D_0000E832DAC0__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CMtx8x8Doc : public CDocument
{
protected: // create from serialization only
	CMtx8x8Doc();
	DECLARE_DYNCREATE(CMtx8x8Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMtx8x8Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMtx8x8Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMtx8x8Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MTX8X8DOC_H__5BF2779D_2144_11D2_A74D_0000E832DAC0__INCLUDED_)
