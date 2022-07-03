
#include "pch.h"
#include "testerPeelVinylAttach.h"
#include "popCfg.h"
#include "afxdialogex.h"
#include "testerPeelVinylAttachDlg.h"

// CpopCfg 대화 상자

IMPLEMENT_DYNAMIC(CpopCfg, CDialogEx)

CpopCfg::CpopCfg(CWnd* pParent /*=nullptr*/)
	: m_TimerID(0), CDialogEx(IDD_POPDLG_CFG, pParent)
{
	CtesterPeelVinylAttachDlg* parent = (CtesterPeelVinylAttachDlg*)pParent;
	m_pSystem = parent->m_pSystem;
}

CpopCfg::~CpopCfg()
{
}

void CpopCfg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CpopCfg, CDialogEx)
	ON_WM_TIMER()
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_CFG_IO_OUT0, &CpopCfg::OnBnClickedCfgIoOut0)
	ON_BN_CLICKED(IDC_CFG_IO_OUT1, &CpopCfg::OnBnClickedCfgIoOut1)
	ON_BN_CLICKED(IDC_CFG_IO_OUT2, &CpopCfg::OnBnClickedCfgIoOut2)
	ON_BN_CLICKED(IDC_CFG_IO_OUT3, &CpopCfg::OnBnClickedCfgIoOut3)
	ON_BN_CLICKED(IDC_CFG_IO_OUT4, &CpopCfg::OnBnClickedCfgIoOut4)
	ON_BN_CLICKED(IDC_CFG_IO_OUT5, &CpopCfg::OnBnClickedCfgIoOut5)
	ON_BN_CLICKED(IDC_CFG_IO_OUT6, &CpopCfg::OnBnClickedCfgIoOut6)
	ON_BN_CLICKED(IDC_CFG_IO_OUT7, &CpopCfg::OnBnClickedCfgIoOut7)
	ON_BN_CLICKED(IDC_CFG_IO_OUT8, &CpopCfg::OnBnClickedCfgIoOut8)
	ON_BN_CLICKED(IDC_CFG_IO_OUT9, &CpopCfg::OnBnClickedCfgIoOut9)
	ON_BN_CLICKED(IDC_CFG_IO_OUT10, &CpopCfg::OnBnClickedCfgIoOut10)
	ON_BN_CLICKED(IDC_CFG_IO_OUT11, &CpopCfg::OnBnClickedCfgIoOut11)
	ON_BN_CLICKED(IDC_CFG_IO_OUT12, &CpopCfg::OnBnClickedCfgIoOut12)
	ON_BN_CLICKED(IDC_CFG_IO_OUT13, &CpopCfg::OnBnClickedCfgIoOut13)
	ON_BN_CLICKED(IDC_CFG_IO_OUT14, &CpopCfg::OnBnClickedCfgIoOut14)
	ON_BN_CLICKED(IDC_CFG_IO_OUT15, &CpopCfg::OnBnClickedCfgIoOut15)
	ON_BN_CLICKED(IDC_CFG_IO_OUT16, &CpopCfg::OnBnClickedCfgIoOut16)
	ON_BN_CLICKED(IDC_CFG_IO_OUT17, &CpopCfg::OnBnClickedCfgIoOut17)
	ON_BN_CLICKED(IDC_CFG_IO_OUT18, &CpopCfg::OnBnClickedCfgIoOut18)
	ON_BN_CLICKED(IDC_CFG_IO_OUT19, &CpopCfg::OnBnClickedCfgIoOut19)
	ON_BN_CLICKED(IDC_CFG_IO_OUT20, &CpopCfg::OnBnClickedCfgIoOut20)
	ON_BN_CLICKED(IDC_CFG_IO_OUT21, &CpopCfg::OnBnClickedCfgIoOut21)
	ON_BN_CLICKED(IDC_CFG_IO_OUT22, &CpopCfg::OnBnClickedCfgIoOut22)
	ON_BN_CLICKED(IDC_CFG_IO_OUT23, &CpopCfg::OnBnClickedCfgIoOut23)
	ON_BN_CLICKED(IDC_CFG_IO_OUT24, &CpopCfg::OnBnClickedCfgIoOut24)
	ON_BN_CLICKED(IDC_CFG_IO_OUT25, &CpopCfg::OnBnClickedCfgIoOut25)
	ON_BN_CLICKED(IDC_CFG_IO_OUT26, &CpopCfg::OnBnClickedCfgIoOut26)
	ON_BN_CLICKED(IDC_CFG_IO_OUT27, &CpopCfg::OnBnClickedCfgIoOut27)
	ON_BN_CLICKED(IDC_CFG_IO_OUT28, &CpopCfg::OnBnClickedCfgIoOut28)
	ON_BN_CLICKED(IDC_CFG_IO_OUT29, &CpopCfg::OnBnClickedCfgIoOut29)
	ON_BN_CLICKED(IDC_CFG_IO_OUT30, &CpopCfg::OnBnClickedCfgIoOut30)
	ON_BN_CLICKED(IDC_CFG_IO_OUT31, &CpopCfg::OnBnClickedCfgIoOut31)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CpopCfg 메시지 처리기


void CpopCfg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnTimer(nIDEvent);
}


void CpopCfg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (bShow == TRUE)
	{
		m_TimerID = SetTimer(UPDATE_TIMER_POP_IO_STATE_DLG, 50, NULL);
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


BOOL CpopCfg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
								// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL CpopCfg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CDialogEx::PreTranslateMessage(pMsg);
}


void CpopCfg::OnBnClickedCfgIoOut0()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut12()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut13()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut14()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut15()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut16()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut17()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut18()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut19()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut20()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut21()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut22()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut23()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut24()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut25()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut26()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut27()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut28()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut29()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut30()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnBnClickedCfgIoOut31()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CpopCfg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (m_TimerID != 0)
	{
		KillTimer(m_TimerID);
		m_TimerID = 0;
	}
}
