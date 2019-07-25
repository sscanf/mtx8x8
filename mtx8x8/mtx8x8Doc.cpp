// mtx8x8Doc.cpp : implementation of the CMtx8x8Doc class
//

#include "stdafx.h"
#include "mtx8x8.h"

#include "mtx8x8Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMtx8x8Doc

IMPLEMENT_DYNCREATE(CMtx8x8Doc, CDocument)

BEGIN_MESSAGE_MAP(CMtx8x8Doc, CDocument)
	//{{AFX_MSG_MAP(CMtx8x8Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMtx8x8Doc construction/destruction

CMtx8x8Doc::CMtx8x8Doc()
{
	// TODO: add one-time construction code here

}

CMtx8x8Doc::~CMtx8x8Doc()
{
}

BOOL CMtx8x8Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMtx8x8Doc serialization

void CMtx8x8Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMtx8x8Doc diagnostics

#ifdef _DEBUG
void CMtx8x8Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMtx8x8Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMtx8x8Doc commands
