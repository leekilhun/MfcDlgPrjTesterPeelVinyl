
// testerPeelVinylAttachDlg.h: 헤더 파일
//

#pragma once


// CtesterPeelVinylAttachDlg 대화 상자
class CtesterPeelVinylAttachDlg : public CDialogEx
{
	UINT_PTR	m_TimerID;

public:
	apSystem* m_pSystem;


// 생성입니다.
public:
	CtesterPeelVinylAttachDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTERPEELVINYLATTACH_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonTest1();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
private:
	void update();
	static void cbFunc(void* obj, void* w_parm, void* l_parm);
public:
	afx_msg void OnLbnSelchangeListReceive();
};
