
// RR-HRN-SimulatorDlg.h: 헤더 파일
//

#pragma once


// CRRHRNSimulatorDlg 대화 상자
class CRRHRNSimulatorDlg : public CDialogEx
{
// 생성입니다.
public:
	CRRHRNSimulatorDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RRHRNSIMULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//RR=0, HRN=1 버튼눌럿을때임
	int m_rSelect;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedButtonRun();
	afx_msg void OnBnClickedButtonQuit();
	// 평균대기시간, 평균반환시간
	CString m_strResultWait;
	CString m_strResultReturn;
	//프로세스별 도착시간
	CString m_strP1Arrive;
	CString m_strP2Arrive;
	CString m_strP3Arrive;
	CString m_strP4Arrive;
	CString m_strP5Arrive;
	CString m_strP6Arrive;
	CString m_strP7Arrive;
	CString m_strP8Arrive;
	CString m_strP9Arrive;
	CString m_strP10Arrive;
	// 프로세스별 서비스시간
	CString m_strP1Service;
	CString m_strP2Service;
	CString m_strP3Service;
	CString m_strP4Service;
	CString m_strP5Service;
	CString m_strP6Service;
	CString m_strP7Service;
	CString m_strP8Service;
	CString m_strP9Service;
	CString m_strP10Service;
	// 프로세스별 대기시간
	CString m_strP1Wait;
	CString m_strP2Wait;
	CString m_strP3Wait;
	CString m_strP4Wait;
	CString m_strP5Wait;
	CString m_strP6Wait;
	CString m_strP7Wait;
	CString m_strP8Wait;
	CString m_strP9Wait;
	CString m_strP10Wait;
	void All_Wait_EnableWindow(int b);
	void RoundRobin();
	void HRN();
	// 프로세스별 우선순위
	CString m_strP1Priority;
	CString m_strP2Priority;
	CString m_strP3Priority;
	CString m_strP4Priority;
	CString m_strP5Priority;
	CString m_strP6Priority;
	CString m_strP7Priority;
	CString m_strP8Priority;
	CString m_strP9Priority;
	CString m_strP10Priority;
	void All_Priority_EnableWindow(int b);
	void All_Arrive_EnableWindow(int b);
	// 프로세스별 반환시간
	CString m_strP1Return;
	CString m_strP2Return;
	CString m_strP3Return;
	CString m_strP4Return;
	CString m_strP5Return;
	CString m_strP6Return;
	CString m_strP7Return;
	CString m_strP8Return;
	CString m_strP9Return;
	CString m_strP10Return;
	void All_Return_EnableWindow(int b);
};
