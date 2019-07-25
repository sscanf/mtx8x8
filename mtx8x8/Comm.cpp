// Comm.cpp: implementation of the CComm class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "mtx8x8.h"
#include "mtx8x8view.h"
#include "Comm.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
UINT monitor (LPVOID param)
{
	HANDLE	hCom;
	HANDLE	hEvent;
	DWORD	dwEvtMask;
	BOOL	fReadStat;
	DWORD	BytesLeidos;
	unsigned char	BufferIn[80];

	int idx=0;

	CComm *pCom = (CComm *)param;
	hCom = pCom->hCom;

	hEvent = CreateEvent (NULL,FALSE,FALSE,NULL);
	while (1)
	{
		memset (BufferIn,0,5);
		SetCommMask(hCom,EV_RXCHAR);
		WaitCommEvent(hCom, &dwEvtMask,0);
		if (dwEvtMask & EV_RXCHAR)
		{
			fReadStat = ReadFile (hCom,BufferIn,80,&BytesLeidos,0);

			if (!fReadStat)
				AfxMessageBox ("Ha habido un error en el puerto de comunicaciones",MB_OK);

			pCom->CommRx(BufferIn,BytesLeidos);
		}
	}
	return 0;
}




CComm::CComm()
{

}

CComm::~CComm()
{

}

CComm::CComm (CString puerto, HWND hWnd)
{
	abrir (puerto, hWnd);
}


CComm::abrir (CString puerto, HWND hWnd)
{
	DCB dcb;
	BOOL fSuccess;
	COMMTIMEOUTS CommTimeOuts;

//	m_pDoc = ptr;
	m_hWnd = hWnd;

	hCom = CreateFile(puerto,
		GENERIC_READ | GENERIC_WRITE,
		0,    /* comm devices must be opened w/exclusive-access */
		NULL, /* no security attrs */
		OPEN_EXISTING, /* comm devices must use OPEN_EXISTING */
		0,    /* not overlapped I/O */
		NULL  /* hTemplate must be NULL for comm devices */
		);

	if (hCom == INVALID_HANDLE_VALUE) return FALSE;

	fSuccess = GetCommState(hCom, &dcb);

	if (!fSuccess) 
		return FALSE;

	/* Fill in the DCB: baud=9600, 8 data bits, no parity, 1 stop bit. */

	dcb.BaudRate	= 9600;
	dcb.ByteSize	= 8;
	dcb.Parity		= NOPARITY;
	dcb.StopBits	= ONESTOPBIT;
	dcb.fBinary		= TRUE;
	dcb.fNull		= FALSE;
	dcb.fRtsControl = RTS_CONTROL_DISABLE;
	dcb.fDtrControl = DTR_CONTROL_DISABLE;
	dcb.fOutxCtsFlow = FALSE;
	dcb.fOutxDsrFlow = FALSE;
	dcb.fDtrControl  = FALSE;


	fSuccess = SetCommState(hCom, &dcb);
	if (!fSuccess) 	return FALSE;

	SetupComm (hCom,512,512);
    CommTimeOuts.ReadIntervalTimeout = 0x10;
    CommTimeOuts.ReadTotalTimeoutMultiplier = 0 ;
    CommTimeOuts.ReadTotalTimeoutConstant = 0 ;
    SetCommTimeouts(hCom, &CommTimeOuts ) ;

	AfxBeginThread (&monitor, this);
	return TRUE;
}

void CComm::CommRx(unsigned char *msg, DWORD len)
{
	DWORD idx=0;
	MsgOk=TRUE;
	
	do
	{
		if (msg[idx-1]==0xa1 && msg[idx-2]==0xec)
		{
			WPARAM wParam;
			LPARAM lParam;
			
			wParam = NULL;
			lParam = msg[idx];
			::SendMessage (m_hWnd, RX_STATUS, wParam, lParam);
			return;
		}
			

	idx++;
	}while (idx<len);
}

DWORD CComm::TxBuff(char * buff, DWORD len)
{
	DWORD bytes=0;
	WriteFile (hCom,buff,len , &bytes, NULL);

	return bytes;
}
