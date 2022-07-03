#pragma once


// CpopCfg 대화 상자

class CpopCfg : public CDialogEx
{
	apSystem* m_pSystem;
	UINT_PTR m_TimerID;
	DECLARE_DYNAMIC(CpopCfg)

public:
	CpopCfg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CpopCfg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_POPDLG_CFG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
private:
	void update();
	bool writeOutReg(uint32_t res_id, uint32_t addr);
	void writeDlgObject();

public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedCfgIoOut0();
	afx_msg void OnBnClickedCfgIoOut1();
	afx_msg void OnBnClickedCfgIoOut2();
	afx_msg void OnBnClickedCfgIoOut3();
	afx_msg void OnBnClickedCfgIoOut4();
	afx_msg void OnBnClickedCfgIoOut5();
	afx_msg void OnBnClickedCfgIoOut6();
	afx_msg void OnBnClickedCfgIoOut7();
	afx_msg void OnBnClickedCfgIoOut8();
	afx_msg void OnBnClickedCfgIoOut9();
	afx_msg void OnBnClickedCfgIoOut10();
	afx_msg void OnBnClickedCfgIoOut11();
	afx_msg void OnBnClickedCfgIoOut12();
	afx_msg void OnBnClickedCfgIoOut13();
	afx_msg void OnBnClickedCfgIoOut14();
	afx_msg void OnBnClickedCfgIoOut15();
	afx_msg void OnBnClickedCfgIoOut16();
	afx_msg void OnBnClickedCfgIoOut17();
	afx_msg void OnBnClickedCfgIoOut18();
	afx_msg void OnBnClickedCfgIoOut19();
	afx_msg void OnBnClickedCfgIoOut20();
	afx_msg void OnBnClickedCfgIoOut21();
	afx_msg void OnBnClickedCfgIoOut22();
	afx_msg void OnBnClickedCfgIoOut23();
	afx_msg void OnBnClickedCfgIoOut24();
	afx_msg void OnBnClickedCfgIoOut25();
	afx_msg void OnBnClickedCfgIoOut26();
	afx_msg void OnBnClickedCfgIoOut27();
	afx_msg void OnBnClickedCfgIoOut28();
	afx_msg void OnBnClickedCfgIoOut29();
	afx_msg void OnBnClickedCfgIoOut30();
	afx_msg void OnBnClickedCfgIoOut31();
	afx_msg void OnDestroy();
};
