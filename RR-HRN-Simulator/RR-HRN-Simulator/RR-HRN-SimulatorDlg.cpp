
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
{
	for (int i = 0; i < 10; i++)
	{
		m_strArrive[i] = _T("");
		m_strService[i] = _T("");
		m_strWait[i] = _T("");
		m_strPriority[i] = _T("");
		m_strReturn[i] = _T("");
	}
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRRHRNSimulatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO_RR, m_rSelect);
	DDX_Text(pDX, IDC_EDIT_RESULT_WAIT, m_strResultWait);
	DDX_Text(pDX, IDC_EDIT_RESULT_RETURN, m_strResultReturn);
	DDX_Text(pDX, IDC_EDIT_P1_ARRIVE, m_strArrive[0]);
	DDX_Text(pDX, IDC_EDIT_P2_ARRIVE, m_strArrive[1]);
	DDX_Text(pDX, IDC_EDIT_P3_ARRIVE, m_strArrive[2]);
	DDX_Text(pDX, IDC_EDIT_P4_ARRIVE, m_strArrive[3]);
	DDX_Text(pDX, IDC_EDIT_P5_ARRIVE, m_strArrive[4]);
	DDX_Text(pDX, IDC_EDIT_P6_ARRIVE, m_strArrive[5]);
	DDX_Text(pDX, IDC_EDIT_P7_ARRIVE, m_strArrive[6]);
	DDX_Text(pDX, IDC_EDIT_P8_ARRIVE, m_strArrive[7]);
	DDX_Text(pDX, IDC_EDIT_P9_ARRIVE, m_strArrive[8]);
	DDX_Text(pDX, IDC_EDIT_P10_ARRIVE, m_strArrive[9]);
	DDX_Text(pDX, IDC_EDIT_P1_SERVICE, m_strService[0]);
	DDX_Text(pDX, IDC_EDIT_P2_SERVICE, m_strService[1]);
	DDX_Text(pDX, IDC_EDIT_P3_SERVICE, m_strService[2]);
	DDX_Text(pDX, IDC_EDIT_P4_SERVICE, m_strService[3]);
	DDX_Text(pDX, IDC_EDIT_P5_SERVICE, m_strService[4]);
	DDX_Text(pDX, IDC_EDIT_P6_SERVICE, m_strService[5]);
	DDX_Text(pDX, IDC_EDIT_P7_SERVICE, m_strService[6]);
	DDX_Text(pDX, IDC_EDIT_P8_SERVICE, m_strService[7]);
	DDX_Text(pDX, IDC_EDIT_P9_SERVICE, m_strService[8]);
	DDX_Text(pDX, IDC_EDIT_P10_SERVICE, m_strService[9]);
	DDX_Text(pDX, IDC_EDIT_P1_WAIT, m_strWait[0]);
	DDX_Text(pDX, IDC_EDIT_P2_WAIT, m_strWait[1]);
	DDX_Text(pDX, IDC_EDIT_P3_WAIT, m_strWait[2]);
	DDX_Text(pDX, IDC_EDIT_P4_WAIT, m_strWait[3]);
	DDX_Text(pDX, IDC_EDIT_P5_WAIT, m_strWait[4]);
	DDX_Text(pDX, IDC_EDIT_P6_WAIT, m_strWait[5]);
	DDX_Text(pDX, IDC_EDIT_P7_WAIT, m_strWait[6]);
	DDX_Text(pDX, IDC_EDIT_P8_WAIT, m_strWait[7]);
	DDX_Text(pDX, IDC_EDIT_P9_WAIT, m_strWait[8]);
	DDX_Text(pDX, IDC_EDIT_P10_WAIT, m_strWait[9]);
	DDX_Text(pDX, IDC_EDIT_P1_PRIORITY, m_strPriority[0]);
	DDX_Text(pDX, IDC_EDIT_P2_PRIORITY, m_strPriority[1]);
	DDX_Text(pDX, IDC_EDIT_P3_PRIORITY, m_strPriority[2]);
	DDX_Text(pDX, IDC_EDIT_P4_PRIORITY, m_strPriority[3]);
	DDX_Text(pDX, IDC_EDIT_P5_PRIORITY, m_strPriority[4]);
	DDX_Text(pDX, IDC_EDIT_P6_PRIORITY, m_strPriority[5]);
	DDX_Text(pDX, IDC_EDIT_P7_PRIORITY, m_strPriority[6]);
	DDX_Text(pDX, IDC_EDIT_P8_PRIORITY, m_strPriority[7]);
	DDX_Text(pDX, IDC_EDIT_P9_PRIORITY, m_strPriority[8]);
	DDX_Text(pDX, IDC_EDIT_P10_PRIORITY, m_strPriority[9]);
	DDX_Text(pDX, IDC_EDIT_P1_RETURN, m_strReturn[0]);
	DDX_Text(pDX, IDC_EDIT_P2_RETURN, m_strReturn[1]);
	DDX_Text(pDX, IDC_EDIT_P3_RETURN, m_strReturn[2]);
	DDX_Text(pDX, IDC_EDIT_P4_RETURN, m_strReturn[3]);
	DDX_Text(pDX, IDC_EDIT_P5_RETURN, m_strReturn[4]);
	DDX_Text(pDX, IDC_EDIT_P6_RETURN, m_strReturn[5]);
	DDX_Text(pDX, IDC_EDIT_P7_RETURN, m_strReturn[6]);
	DDX_Text(pDX, IDC_EDIT_P8_RETURN, m_strReturn[7]);
	DDX_Text(pDX, IDC_EDIT_P9_RETURN, m_strReturn[8]);
	DDX_Text(pDX, IDC_EDIT_P10_RETURN, m_strReturn[9]);
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
	All_Priority_EnableWindow(FALSE);

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
	All_Priority_EnableWindow(FALSE);
	All_Arrive_EnableWindow(TRUE);
}


void CRRHRNSimulatorDlg::OnBnClickedRadio2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	All_Priority_EnableWindow(TRUE);
	All_Arrive_EnableWindow(FALSE);
}


void CRRHRNSimulatorDlg::OnBnClickedButtonRun()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (!m_rSelect)//RR
	{
		RoundRobin(); // 산해 이 함수를 구현하면 됨
	}
	else
	{
		HRN(); // 영태 이 함수를 구현하면 됨
	}
}


void CRRHRNSimulatorDlg::OnBnClickedButtonQuit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PostQuitMessage(0);
}


void CRRHRNSimulatorDlg::All_Wait_EnableWindow(int b)
{
	// TODO: 여기에 구현 코드 추가.
	GetDlgItem(IDC_EDIT_P1_WAIT)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P2_WAIT)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P3_WAIT)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P4_WAIT)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P5_WAIT)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P6_WAIT)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P7_WAIT)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P8_WAIT)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P9_WAIT)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P10_WAIT)->EnableWindow(b);
}


void CRRHRNSimulatorDlg::RoundRobin()
{
	// TODO: 여기에 구현 코드 추가.
	UpdateData(TRUE);
	int TotalRunnningTime = 0,
		PS_ARRIVE[10], PS_WAIT[10] = { 0, }, PS_RETURN[10] = { 0, }, PS_PRIORITY[10] = { 0, },
		PS_SERVICE[10], MaxPriority = 0, TimeSlice = 0, PS_SERVICE_COPY[10], sw = 0;
	// 도착시간, 서비스시간구하기, 서비스시간 복사, 총 실행시간 구하기
	for (int i = 0; i < 10; i++)
	{
		PS_ARRIVE[i] = _tstoi(m_strArrive[i]);
		PS_SERVICE[i] = _tstoi(m_strService[i]);
		if (PS_SERVICE[i] == 0)
		{
			PS_SERVICE[i] = -1;
		}
		PS_SERVICE_COPY[i] = PS_SERVICE[i];
		TotalRunnningTime += PS_SERVICE[i];
	}
	// 대기시간구하기
	for (int i = 0; i < TotalRunnningTime; i++)
	{
		// 1.1. 현재 진행중인 프로세스가 없을때
		if (!sw)
		{
			// 1. 현시간에 시작된 프로세스 우선순위++;
			for (int j = 0; j < 10; j++)
			{
				if (PS_ARRIVE[j] == i)
				{
					PS_PRIORITY[j]++;
				}
			}
			// 1.1.1. 프로세스 우선순위중 가장 높은것 구하기 MaxPriority
			for (int j = 0; j < 10; j++)
			{
				if (PS_PRIORITY[j] > PS_PRIORITY[MaxPriority])
				{
					MaxPriority = j;
				}
			}
			PS_SERVICE_COPY[MaxPriority]--;
			TimeSlice++;
			// 나머지 프로세스들에 대기값들을 더한다.
			for (int j = 0; j < 10; j++)
			{
				if ((j != MaxPriority) && (PS_SERVICE_COPY[j] > 0) && 
					(PS_ARRIVE[j] <= i))
				{
					PS_WAIT[j]++;
					PS_PRIORITY[j]++;
				}
			}
			sw = 1;
		}
		// 1.2. 현재 진행준인 프로세스가 있을때
		else
		{
			TimeSlice++;
			if (PS_SERVICE_COPY[MaxPriority] > 0)
			{
				// 1. 현시간에 시작된 프로세스 우선순위++;
				for (int j = 0; j < 10; j++)
				{
					if (PS_ARRIVE[j] == i)
					{
						PS_PRIORITY[j]++;
					}
				}
				PS_SERVICE_COPY[MaxPriority]--;
				// 나머지 프로세스들에 대기값들을 더한다.
				for (int j = 0; j < 10; j++)
				{
					if ((j != MaxPriority) && (PS_SERVICE_COPY[j] > 0) &&
						(PS_ARRIVE[j] <= i))
					{
						PS_WAIT[j]++;
						PS_PRIORITY[j]++;
					}
				}
			}
			// 프로세스가 끝날때
			else
			{
				sw = 0;
				PS_PRIORITY[MaxPriority] = 0;
				MaxPriority = 0;
				TimeSlice = 0;
				i--;
				continue;
			}
			if (TimeSlice == 4)
			{
				sw = 0;
				PS_PRIORITY[MaxPriority] = 0;
				MaxPriority = 0;
				TimeSlice = 0;
			}
		}
		
		// 2. 우선순위가 가장 높은 프로세스 실행 및 우선순위 초기화
		// 3. 남은프로세스들은 우선순위 높여주기(이번에 도착한애는 우선순위 높이면 안됨)
	}
	// 반환시간 = 서비스시간 + 대기시간 - 도차시간, 반환시간 대입, 대기시간 대입
	int resultWait = 0, resultReturn = 0, count = 0;

	for (int i = 0; i < 10; i++)
	{
		PS_RETURN[i] = PS_SERVICE[i] + PS_WAIT[i];
		if ((PS_RETURN[i] != -1))
		{
			m_strReturn[i].Format(_T("%d"), PS_RETURN[i]);
			m_strWait[i].Format(_T("%d"), PS_WAIT[i]);
			count++;
		}
		else
		{
			m_strReturn[i] = _T("");
			m_strWait[i] = _T("");
		}
		resultReturn += PS_RETURN[i];
		resultWait += PS_WAIT[i];
	}
	m_strResultReturn.Format(_T("%.2f"), (float)resultReturn / count);
	m_strResultWait.Format(_T("%.2f"), (float)resultWait / count);

	UpdateData(FALSE);
}


void CRRHRNSimulatorDlg::HRN()
{
	// TODO: 여기에 구현 코드 추가.
	double AvgSum = 0;
	double RetSum = 0;
	double AvgWait[10] = { 0, };
	double RetTime[10] = { 0, };
	double Priority[10] = { 0, };
	double Ret[10] = { 0, };
	double StateRet[10] = { 0, };
	//Formatting 
	CString Pr[10] = { 0, };
	CString Re[10] = { 0, };
	CString AllAvg = 0;
	CString AllRet = 0;
	// ==============================================
	for (int i = 0; i < 10; i++) {
		Priority[i] = _wtof(m_strService[i]) + _wtof(m_strWait[i]) / _wtof(m_strService[i]);
	}

	for (int i = 0; i < 10; i++) {
		Pr[i].Format(_T("%.2lf"), Priority[i]);
	}
	for (int i = 0; i < 10; i++) {
		m_strPriority[i] = Pr[i];
	}
	// ==============================================

	for (int i = 0; i < 10; i++) {
		AvgWait[i] = _wtoi(m_strWait[i]);
		AvgSum += AvgWait[i];
	}
	AllAvg.Format(_T("%.2lf"), AvgSum / 10);
	m_strResultWait = AllAvg;
	// ===============================================

	for (int i = 0; i < 10; i++) {
		Ret[i] = _wtof(m_strService[i]) + _wtof(m_strWait[i]);
	}

	for (int i = 0; i < 10; i++) {
		Re[i].Format(_T("%.2lf"), Ret[i]);
	}

	for (int i = 0; i < 10; i++) {
		m_strReturn[i] = Re[i];
		RetSum += Ret[i];
	}

	AllRet.Format(_T("%.2lf"), RetSum);
	m_strResultReturn = AllRet;

	UpdateData(FALSE);
}


void CRRHRNSimulatorDlg::All_Priority_EnableWindow(int b)
{
	// TODO: 여기에 구현 코드 추가.
	GetDlgItem(IDC_EDIT_P1_PRIORITY)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P2_PRIORITY)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P3_PRIORITY)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P4_PRIORITY)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P5_PRIORITY)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P6_PRIORITY)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P7_PRIORITY)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P8_PRIORITY)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P9_PRIORITY)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P10_PRIORITY)->EnableWindow(b);
}


void CRRHRNSimulatorDlg::All_Arrive_EnableWindow(int b)
{
	// TODO: 여기에 구현 코드 추가.
	GetDlgItem(IDC_EDIT_P1_ARRIVE)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P2_ARRIVE)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P3_ARRIVE)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P4_ARRIVE)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P5_ARRIVE)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P6_ARRIVE)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P7_ARRIVE)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P8_ARRIVE)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P9_ARRIVE)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P10_ARRIVE)->EnableWindow(b);
}


void CRRHRNSimulatorDlg::All_Return_EnableWindow(int b)
{
	// TODO: 여기에 구현 코드 추가.
	GetDlgItem(IDC_EDIT_P1_RETURN)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P2_RETURN)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P3_RETURN)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P4_RETURN)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P5_RETURN)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P6_RETURN)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P7_RETURN)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P8_RETURN)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P9_RETURN)->EnableWindow(b);
	GetDlgItem(IDC_EDIT_P10_RETURN)->EnableWindow(b);
}
