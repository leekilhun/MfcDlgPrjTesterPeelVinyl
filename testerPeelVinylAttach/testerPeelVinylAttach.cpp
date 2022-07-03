
// testerPeelVinylAttach.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "testerPeelVinylAttach.h"
#include "testerPeelVinylAttachDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtesterPeelVinylAttachApp

BEGIN_MESSAGE_MAP(CtesterPeelVinylAttachApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CtesterPeelVinylAttachApp 생성

CtesterPeelVinylAttachApp::CtesterPeelVinylAttachApp():m_pSystem(new apSystem())
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CtesterPeelVinylAttachApp 개체입니다.

CtesterPeelVinylAttachApp theApp;

void IncreaseCnt(void);
bool progressbar(void);

extern HINSTANCE g_hinst;

void IncreaseCnt() 
{
	AfxMessageBox(L"OK");

}

bool progressbar()
{
	//https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=wlvkddlwkd&logNo=220887678529

	PVOID pOldValue = NULL;
	Wow64DisableWow64FsRedirection(&pOldValue);

	STARTUPINFO si = { 0 };
	si.cb = sizeof(STARTUPINFO);
	PROCESS_INFORMATION pi = { 0 };

	//클래스 멤버 변수 선언
	SHELLEXECUTEINFO m_sInfo;

	//외부 어플리케이션 실행
	ZeroMemory(&m_sInfo, sizeof(SHELLEXECUTEINFO));
	m_sInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	m_sInfo.lpFile = L"C:\\_out\\UIProgress.exe";//L"C:\\Windows\\System32\\OSK.EXE";
	m_sInfo.lpParameters = L"1 2 3 4 5 6 7"; //전달 인자
	m_sInfo.nShow = SW_SHOWMINIMIZED; //실행시 최소화
	m_sInfo.lpVerb = L"open"; //관리자 권한 실행을 원할 때 "runas"
	m_sInfo.fMask = SEE_MASK_NOCLOSEPROCESS; //프로세스 핸들값 사용
	m_sInfo.nShow = SW_SHOW;

	if (ShellExecuteEx(&m_sInfo))
	{
		TRACE("ShellExecuteEx Success\n");
	}
	else
	{
		TRACE("ShellExecuteEx Failed\n");
		return false;
	}

	Wow64RevertWow64FsRedirection(pOldValue);
	return true;



}
// CtesterPeelVinylAttachApp 초기화

BOOL CtesterPeelVinylAttachApp::InitInstance()
{
	CWinApp::InitInstance();

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	//CString cst;
	//cst.Format(L"argc = %d", __argc);
	//AfxMessageBox(cst);



	buffer::_que<byte> _que_buff;


	flag::fdata regist_data(5);
	regist_data[(uint8_t)1][REG_BIT(3)] = true;

	uint8_t flag_data = regist_data[(int)1];

	//progressbar();





	m_pSystem->Initialize(/*progressbar*/);



	CtesterPeelVinylAttachDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 여기에 [확인]을 클릭하여 대화 상자가 없어질 때 처리할
		//  코드를 배치합니다.
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 여기에 [취소]를 클릭하여 대화 상자가 없어질 때 처리할
		//  코드를 배치합니다.
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "경고: 대화 상자를 만들지 못했으므로 애플리케이션이 예기치 않게 종료됩니다.\n");
		TRACE(traceAppMsg, 0, "경고: 대화 상자에서 MFC 컨트롤을 사용하는 경우 #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS를 수행할 수 없습니다.\n");
	}
	
	// 대화 상자가 닫혔으므로 응용 프로그램의 메시지 펌프를 시작하지 않고 응용 프로그램을 끝낼 수 있도록 FALSE를
	// 반환합니다.
	return FALSE;
}


apSystem* CtesterPeelVinylAttachApp::GetSystem()
{
	return m_pSystem;
}

int CtesterPeelVinylAttachApp::ExitInstance()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (m_pSystem)
		delete m_pSystem;
	m_pSystem = nullptr;
	return CWinApp::ExitInstance();
}
