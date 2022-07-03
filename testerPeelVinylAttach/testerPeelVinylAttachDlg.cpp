
// testerPeelVinylAttachDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "testerPeelVinylAttach.h"
#include "testerPeelVinylAttachDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtesterPeelVinylAttachDlg 대화 상자



CtesterPeelVinylAttachDlg::CtesterPeelVinylAttachDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TESTERPEELVINYLATTACH_DIALOG, pParent)
{
	m_pSystem = nullptr;
	m_TimerID = 0;

	CtesterPeelVinylAttachApp* pApp = (CtesterPeelVinylAttachApp*)AfxGetApp();
	m_pSystem = pApp->GetSystem();
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtesterPeelVinylAttachDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CtesterPeelVinylAttachDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_TEST1, &CtesterPeelVinylAttachDlg::OnBnClickedButtonTest1)
	ON_WM_SHOWWINDOW()
	ON_WM_TIMER()
	ON_LBN_SELCHANGE(IDC_LIST_RECEIVE, &CtesterPeelVinylAttachDlg::OnLbnSelchangeListReceive)
END_MESSAGE_MAP()


// CtesterPeelVinylAttachDlg 메시지 처리기

BOOL CtesterPeelVinylAttachDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	netSocket* ethernet = m_pSystem->GetEthernetComponent();
	ethernet->AttCallbackFunc(this, cbFunc);


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CtesterPeelVinylAttachDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CtesterPeelVinylAttachDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CtesterPeelVinylAttachDlg::OnBnClickedButtonTest1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	netSocket* ethernet = m_pSystem->GetEthernetComponent();
	uint8_t data[5] = { 0, };
	data[0] = 0xaa;
	data[1] = 0x03;
	data[2] = 0x01;
	data[3] = 0x00;
	data[4] = 0xc5;

	ethernet->SendData((const char*)data,5);
}


void CtesterPeelVinylAttachDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (bShow == TRUE)
	{
		m_TimerID = SetTimer(UPDATE_TIMER_MAIN_DLG, 100, NULL);
	}
	else
	{
		if (m_TimerID != 0)
		{
			KillTimer(m_TimerID);
			m_TimerID = 0;
		}
	}
}


void CtesterPeelVinylAttachDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	update();
	CDialogEx::OnTimer(nIDEvent);
}


BOOL CtesterPeelVinylAttachDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.


	return CDialogEx::PreTranslateMessage(pMsg);
}

void CtesterPeelVinylAttachDlg::update()
{
	netSocket* p_net = m_pSystem->GetEthernetComponent();
	if (p_net->IsOpened())
	{
		SetDlgItemText(IDC_INFO_CONNECT, L"서버 Device 연결됨");
	}
	else
	{
		SetDlgItemText(IDC_INFO_CONNECT, L"서버 Device 연결 대기");
	}


}

void CtesterPeelVinylAttachDlg::cbFunc(void* obj, void* w_parm, void* l_parm)
{
	CtesterPeelVinylAttachDlg* pThis = (CtesterPeelVinylAttachDlg*)obj;

	uint8_t tmp[480] = { 0, };
	uint8_t hex2char[80] = { 0, };

	if (w_parm == 0)
	{
		sprintf_s((char* const)tmp, sizeof(tmp), "Alarm - %s ", (char*)l_parm);
	}
	else
	{
		int length = *((int*)w_parm);
		int index = 0;

		for (index = 0; index < length; index++)
		{
			uint8_t data = *((uint8_t*)l_parm + index);
			sprintf_s((char* const)hex2char, sizeof(hex2char), "0x%02X ", data);
			if ((index > 0) && (index % 16 == 0))
			{

			}
			else
			{
				//	memcpy()
				strncat_s((char* const)tmp, sizeof(tmp), (const char*)hex2char, 5);
			}
		}
	}

	

	CString str = trans::CharToCString((char*)&tmp[0]);
	CListBox* listbox =	(CListBox *)pThis->GetDlgItem(IDC_LIST_RECEIVE);
	if (listbox->GetCount() == 10)
	{
		listbox->ResetContent();
	}
	listbox->AddString(str);


}


void CtesterPeelVinylAttachDlg::OnLbnSelchangeListReceive()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	((CListBox*)GetDlgItem(IDC_LIST_RECEIVE))->ResetContent();
}
