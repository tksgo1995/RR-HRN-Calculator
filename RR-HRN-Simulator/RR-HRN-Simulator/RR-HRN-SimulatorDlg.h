
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
	CString m_strArrive[10];
	// 프로세스별 서비스시간
	CString m_strService[10];
	// 프로세스별 대기시간
	CString m_strWait[10];
	void All_Wait_EnableWindow(int b);
	void RoundRobin();
	void HRN();
	// 프로세스별 우선순위
	CString m_strPriority[10];
	void All_Priority_EnableWindow(int b);
	void All_Arrive_EnableWindow(int b);
	// 프로세스별 반환시간
	CString m_strReturn[10];
	void All_Return_EnableWindow(int b);
	afx_msg void OnEnChangeEditResultWait();
};
