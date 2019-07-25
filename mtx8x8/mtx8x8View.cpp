// mtx8x8View.cpp : implementation of the CMtx8x8View class
//

#include "stdafx.h"
#include "mtx8x8.h"

#include "mtx8x8Doc.h"
#include "mtx8x8View.h"
#include "Comm.h"	// Added by ClassView

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMtx8x8View

IMPLEMENT_DYNCREATE(CMtx8x8View, CFormView)

BEGIN_MESSAGE_MAP(CMtx8x8View, CFormView)
	//{{AFX_MSG_MAP(CMtx8x8View)
	ON_BN_CLICKED(IDC_ESCRIBIR, OnEscribir)
	ON_MESSAGE (RX_STATUS,OnRxStatus)
	ON_BN_CLICKED(IDC_LEER, OnLeer)
	ON_BN_CLICKED(IDC_BORRAR, OnBorrar)
	ON_BN_CLICKED(IDC_ACTIVAR, OnActivar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMtx8x8View construction/destruction

CMtx8x8View::CMtx8x8View()
	: CFormView(CMtx8x8View::IDD)
{
	//{{AFX_DATA_INIT(CMtx8x8View)
	m_EntradaTx = 0;
	m_EntradaRx = 0;
	m_salida1 = FALSE;
	m_salida2 = FALSE;
	m_salida3 = FALSE;
	m_salida4 = FALSE;
	m_salida5 = FALSE;
	m_salida6 = FALSE;
	m_salida7 = FALSE;
	m_salida8 = FALSE;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

	m_bSalidaTx=0;
	m_bEntradaTx=0;
}

CMtx8x8View::~CMtx8x8View()
{
}

void CMtx8x8View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMtx8x8View)
	DDX_Control(pDX, IDC_SPIN2, m_BudRead);
	DDX_Control(pDX, IDC_SPIN1, m_BudWrite);
	DDX_Text(pDX, IDC_EDIT2, m_EntradaTx);
	DDV_MinMaxUInt(pDX, m_EntradaTx, 0, 255);
	DDX_Text(pDX, IDC_EDIT4, m_EntradaRx);
	DDV_MinMaxUInt(pDX, m_EntradaRx, 0, 255);
	DDX_Check(pDX, IDC_CHECK1, m_salida1);
	DDX_Check(pDX, IDC_CHECK2, m_salida2);
	DDX_Check(pDX, IDC_CHECK3, m_salida3);
	DDX_Check(pDX, IDC_CHECK4, m_salida4);
	DDX_Check(pDX, IDC_CHECK5, m_salida5);
	DDX_Check(pDX, IDC_CHECK6, m_salida6);
	DDX_Check(pDX, IDC_CHECK7, m_salida7);
	DDX_Check(pDX, IDC_CHECK8, m_salida8);
	//}}AFX_DATA_MAP
}

BOOL CMtx8x8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMtx8x8View diagnostics

#ifdef _DEBUG
void CMtx8x8View::AssertValid() const
{
	CFormView::AssertValid();
}

void CMtx8x8View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMtx8x8Doc* CMtx8x8View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMtx8x8Doc)));
	return (CMtx8x8Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMtx8x8View message handlers

void CMtx8x8View::OnEscribir() 
{
	char buffer[80];
	int n;
	UCHAR cmd;
	unsigned char byte=0;
	CButton *pButton;

	UpdateData (TRUE);

	for (n=0;n<8;n++)
	{
		pButton= (CButton *)GetDlgItem (n+IDC_CHECK9);

		if (pButton->GetState())
		{
			byte=byte>>1;
			byte|=0x80;
		}
		else
		{
			byte=byte>>1;
			byte&=0x7f;
		}

	}
	cmd=m_EntradaTx|0x80;

	buffer[0]=(char)0xec;
	buffer[1]=(char)0xa1;
	buffer[2]=cmd;
	buffer[3]=byte;
	
	m_pCom->TxBuff (buffer,4);
}

void CMtx8x8View::OnRxStatus(WPARAM wParam, LPARAM lParam)
{

	char byte=0x1;
	CButton *pButton;

	for (int n=0;n<8;n++)
	{
		char res;

		pButton = (CButton *)GetDlgItem(n+IDC_CHECK1);

		res = lParam&byte;
		byte=byte<<1;

		if (res)
		{
			switch (n)
			{
				case 0:
					m_salida1 = TRUE;
				break;

				case 1:
					m_salida2 = TRUE;
				break;

				case 2:
					m_salida3= TRUE;
				break;

				case 3:
					m_salida4= TRUE;
				break;

				case 4:
					m_salida5= TRUE;
				break;

				case 5:
					m_salida6= TRUE;
				break;

				case 6:
					m_salida7= TRUE;
				break;

				case 7:
					m_salida8= TRUE;
				break;
				UpdateData (FALSE);
			}				
		}

		if (!res)
		{
			switch (n)
			{
				case 0:
					m_salida1 = FALSE;
				break;

				case 1:
					m_salida2 = FALSE;
				break;

				case 2:
					m_salida3= FALSE;
				break;

				case 3:
					m_salida4= FALSE;
				break;

				case 4:
					m_salida5= FALSE;
				break;

				case 5:
					m_salida6= FALSE;
				break;

				case 6:
					m_salida7= FALSE;
				break;

				case 7:
					m_salida8= FALSE;
				break;
			}
		}
	}
	UpdateData (FALSE);
}


void CMtx8x8View::OnLeer() 
{

	UpdateData (TRUE);

	char buffer[80];
	UCHAR cmd=0;

	UpdateData (TRUE);

	cmd=m_EntradaRx&0x7f;

	buffer[0]=(char)0xec;
	buffer[1]=(char)0xa1;
	buffer[2]=cmd;
	buffer[3]=NULL;
	
	m_pCom->TxBuff (buffer,3);

}

void CMtx8x8View::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();

	m_EntradaRx=1;
	m_EntradaTx=1;
	
	m_pCom = new CComm ("COM2",m_hWnd);
	UpdateData (FALSE);

	m_BudRead.SetRange (1,8);
	m_BudWrite.SetRange (1,8);
	
	
}

void CMtx8x8View::OnBorrar() 
{
	int n;

	CButton *pButton;

	for (n=0;n<8;n++)
	{
		pButton=(CButton *)GetDlgItem (n+IDC_CHECK9);
		pButton->SetCheck (FALSE);

	}
}

void CMtx8x8View::OnActivar() 
{
	int n;

	CButton *pButton;

	for (n=0;n<8;n++)
	{
		pButton=(CButton *)GetDlgItem (n+IDC_CHECK9);
		pButton->SetCheck (TRUE);

	}
	
}
