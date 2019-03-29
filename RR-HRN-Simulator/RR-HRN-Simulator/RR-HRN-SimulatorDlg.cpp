
// RR-HRN-SimulatorDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "RR-HRN-Simulator.h"
#include "RR-HRN-SimulatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRRHRNSimulatorDlg 대화 상자



CRRHRNSimulatorDlg::CRRHRNSimulatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RRHRNSIMULATOR_DIALOG, pParent)
	, m_rSelect(0)
	, m_strResultWait(_T(""))
	, m_strResultReturn(_T(""))
	, m_strP1Arrive(_T(""))
	, m_strP2Arrive(_T(""))
	, m_strP3Arrive(_T(""))
	, m_strP4Arrive(_T(""))
	, m_strP1Service(_T(""))
	, m_strP1Wait(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRRHRNSimulatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO_RR, m_rSelect);
	DDX_Text(pDX, IDC_EDIT_RESULT_WAIT, m_strResultWait);
	DDX_Text(pDX, IDC_EDIT_RESULT_RETURN, m_strResultReturn);
	DDX_Text(pDX, IDC_EDIT_P1_ARRIVE, m_strP1Arrive);
	DDX_Text(pDX, IDC_EDIT_P2_ARRIVE, m_strP2Arrive);
	DDX_Text(pDX, IDC_EDIT_P3_ARRIVE, m_strP3Arrive);
	DDX_Text(pDX, IDC_EDIT_P4_ARRIVE, m_strP4Arrive);
	DDX_Text(pDX, IDC_EDIT_P5_ARRIVE, m_strP5Arrive);
	DDX_Text(pDX, IDC_EDIT_P6_ARRIVE, m_strP6Arrive);
	DDX_Text(pDX, IDC_EDIT_P7_ARRIVE, m_strP7Arrive);
	DDX_Text(pDX, IDC_EDIT_P8_ARRIVE, m_strP8Arrive);
	DDX_Text(pDX, IDC_EDIT_P9_ARRIVE, m_strP9Arrive);
	DDX_Text(pDX, IDC_EDIT_P10_ARRIVE, m_strP10Arrive);
	DDX_Text(pDX, IDC_EDIT_P1_SERVICE, m_strP1Service);
	DDX_Text(pDX, IDC_EDIT_P2_SERVICE, m_strP2Service);
	DDX_Text(pDX, IDC_EDIT_P3_SERVICE, m_strP3Service);
	DDX_Text(pDX, IDC_EDIT_P4_SERVICE, m_strP4Service);
	DDX_Text(pDX, IDC_EDIT_P5_SERVICE, m_strP5Service);
	DDX_Text(pDX, IDC_EDIT_P6_SERVICE, m_strP6Service);
	DDX_Text(pDX, IDC_EDIT_P7_SERVICE, m_strP7Service);
	DDX_Text(pDX, IDC_EDIT_P8_SERVICE, m_strP8Service);
	DDX_Text(pDX, IDC_EDIT_P9_SERVICE, m_strP9Service);
	DDX_Text(pDX, IDC_EDIT_P10_SERVICE, m_strP10Service);
	DDX_Text(pDX, IDC_EDIT_P1_WAIT, m_strP1Wait);
	DDX_Text(pDX, IDC_EDIT_P2_WAIT, m_strP2Wait);
	DDX_Text(pDX, IDC_EDIT_P3_WAIT, m_strP3Wait);
	DDX_Text(pDX, IDC_EDIT_P4_WAIT, m_strP4Wait);
	DDX_Text(pDX, IDC_EDIT_P5_WAIT, m_strP5Wait);
	DDX_Text(pDX, IDC_EDIT_P6_WAIT, m_strP6Wait);
	DDX_Text(pDX, IDC_EDIT_P7_WAIT, m_strP7Wait);
	DDX_Text(pDX, IDC_EDIT_P8_WAIT, m_strP8Wait);
	DDX_Text(pDX, IDC_EDIT_P9_WAIT, m_strP9Wait);
	DDX_Text(pDX, IDC_EDIT_P10_WAIT, m_strP10Wait);
}

BEGIN_MESSAGE_MAP(CRRHRNSimulatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO_RR, &CRRHRNSimulatorDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO_HRN, &CRRHRNSimulatorDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON_RUN, &CRRHRNSimulatorDlg::OnBnClickedButtonRun)
	ON_BN_CLICKED(IDC_BUTTON_QUIT, &CRRHRNSimulatorDlg::OnBnClickedButtonQuit)
END_MESSAGE_MAP()


// CRRHRNSimulatorDlg 메시지 처리기

BOOL CRRHRNSimulatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	AfxMessageBox(_T("Hello Git!!"));

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CRRHRNSimulatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CRRHRNSimulatorDlg::OnPaint()
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
HCURSOR CRRHRNSimulatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRRHRNSimulatorDlg::OnBnClickedRadio1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
}


void CRRHRNSimulatorDlg::OnBnClickedRadio2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CRRHRNSimulatorDlg::OnBnClickedButtonRun()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CRRHRNSimulatorDlg::OnBnClickedButtonQuit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
