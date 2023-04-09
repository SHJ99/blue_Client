// ChattingClientDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ChattingClient.h"
#include "ChattingClientDlg.h"
#include<atlimage.h>
#include <mmsystem.h> 
#pragma comment(lib, "winmm")
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CChattingClientDlg 대화 상자




CChattingClientDlg::CChattingClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChattingClientDlg::IDD, pParent)
	, m_strData(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	islandturn = 0;
}

void CChattingClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Text(pDX, IDC_EDIT1, m_strData);
	DDX_Control(pDX, IDC_BUTTON_SEND, m_ButtonSend);
	DDX_Control(pDX, IDC_BUTTON_CONNECT, m_ButtonConnect);
	//  DDX_Control(pDX, IDC_BUTTON1, m_pic1);
	DDX_Control(pDX, IDC_BUTTON1, m_dice);
	DDX_Control(pDX, IDC_RADIO1, m_hotel);
	DDX_Control(pDX, IDC_RADIO2, m_building);
	DDX_Control(pDX, IDC_RADIO3, m_villa);
	DDX_Control(pDX, IDC_RADIO4, m_none);
	DDX_Control(pDX, IDC_LIST2, dice_list);
	DDX_Control(pDX, IDC_LIST3, my_money);
	DDX_Control(pDX, IDC_LIST4, my_city);
	DDX_Control(pDX, IDC_LIST5, my_structure);
	DDX_Control(pDX, IDC_DICE1, m_dice1);
	DDX_Control(pDX, IDC_DICE2, m_dice2);
}

BEGIN_MESSAGE_MAP(CChattingClientDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CChattingClientDlg::OnBnClickedButtonSend)
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, &CChattingClientDlg::OnBnClickedButtonConnect)
	ON_BN_CLICKED(IDOK, &CChattingClientDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CChattingClientDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CChattingClientDlg::OnBnClickedButton3)
//	ON_WM_LBUTTONDOWN()
//ON_WM_KEYDOWN()
ON_WM_SETCURSOR()
ON_WM_ERASEBKGND()
ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CChattingClientDlg 메시지 처리기

BOOL CChattingClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	CString money;
	now = 0;
	sequence2 = 0;
	turn = 0;
	me = 0;
	
	money.Format(L"%d", 10000000);
	my_money.AddString(money);//시작금액 백만원

	CString str; //city배열에 도시명 넣기
	str.Format(L"출발");
	city[0] = str;
	str.Format(L"타이베이");
	city[1] = str;
	str.Format(L"베이징");
	city[2] = str;
	str.Format(L"마닐라");
	city[3] = str;
	str.Format(L"제주도");
	city[4] = str;
	str.Format(L"싱가포르");
	city[5] = str;
	str.Format(L"카이로");
	city[6] = str;
	str.Format(L"이스탄불");
	city[7] = str;
	str.Format(L"무인도");
	city[8] = str;
	str.Format(L"아테네");
	city[9] = str;
	str.Format(L"코펜하겐");
	city[10] = str;
	str.Format(L"스톡홀름");
	city[11] = str;
	str.Format(L"콩코드여객기");
	city[12] = str;
	str.Format(L"베른");
	city[13] = str;
	str.Format(L"베를린");
	city[14] = str;
	str.Format(L"오타와");
	city[15] = str;
	str.Format(L"복지기금수령");
	city[16] = str;
	str.Format(L"부에노스아이레스");
	city[17] = str;
	str.Format(L"상파울로");
	city[18] = str;
	str.Format(L"시드니");
	city[19] = str;
	str.Format(L"부산");
	city[20] = str;
	str.Format(L"하와이");
	city[21] = str;
	str.Format(L"리스본");
	city[22] = str;
	str.Format(L"마드리드");
	city[23] = str;
	str.Format(L"우주여행");
	city[24] = str;
	str.Format(L"도쿄");
	city[25] = str;
	str.Format(L"파리");
	city[26] = str;
	str.Format(L"로마");
	city[27] = str;
	str.Format(L"런던");
	city[28] = str;
	str.Format(L"뉴욕");
	city[29] = str;
	str.Format(L"복지기금접수");
	city[30] = str;
	str.Format(L"서울");
	city[31] = str;

	for (int i = 0; i < 32; i++) { //건설비용 초기화. 무인도와 교통수단 포함 0
		land_price[i]=0;
		hotel_price[i]=0;
		build_price[i]=0;
		villa_price[i]=0;
	}
	for (int i = 1; i < 8; i++) { //한 줄의 건설비용은 모두 같다.
		hotel_price[i] = 250000;
		build_price[i] = 150000;
		villa_price[i] = 50000;
	}
	for (int i = 9; i < 16; i++) {
		hotel_price[i] = 500000;
		build_price[i] = 300000;
		villa_price[i] = 100000;
	}
	for (int i = 17; i < 24; i++) {
		hotel_price[i] = 750000;
		build_price[i] = 450000;
		villa_price[i] = 150000;
	}
	for (int i = 25; i < 32; i++) {
		hotel_price[i] = 1000000;
		build_price[i] = 600000;
		villa_price[i] = 200000;
	}
	land_price[4] = 200000; //제주도
	land_price[12] = 200000; //콩코드 여객기
	land_price[20] = 200000; //부산
	land_price[30] = 150000; //복지기금접수
	land_price[31] = 1000000; //서울
	land_pay[0] = 0;
	land_pay[1] = 2000;
	land_pay[2] = 2000;
	land_pay[3] = 4000;
	land_pay[4] = 300000;

	land_pay[5] = 6000;
	land_pay[6] = 6000;
	land_pay[7] = 8000;
	land_pay[8] = 0;//무인도

	land_pay[9] = 10000;
	land_pay[10] = 10000;
	land_pay[11] = 12000;
	land_pay[12] = 300000;

	land_pay[13] = 14000;
	land_pay[14] = 14000;
	land_pay[15] = 16000;
	land_pay[16] = 150000;//복지기금수령

	land_pay[17] = 18000;
	land_pay[18] = 20000;
	land_pay[19] = 20000;
	land_pay[20] = 600000;

	land_pay[21] = 22000;
	land_pay[22] = 22000;
	land_pay[23] = 24000;
	land_pay[24] = 0;//우주여행

	land_pay[25] = 26000;
	land_pay[26] = 28000;
	land_pay[27] = 28000;
	land_pay[28] = 35000;

	land_pay[29] = 35000;
	land_pay[30] = 0;
	land_pay[31] = 2000000;

	//hotel
	hotel_pay[0] = 0;
	hotel_pay[1] = 250000;
	hotel_pay[2] = 250000;
	hotel_pay[3] = 250000;
	hotel_pay[4] = 300000;

	hotel_pay[5] = 550000;
	hotel_pay[6] = 550000;
	hotel_pay[7] = 600000;
	hotel_pay[8] = 0;//무인도

	hotel_pay[9] = 750000;
	hotel_pay[10] = 750000;
	hotel_pay[11] = 900000;
	hotel_pay[12] = 300000;

	hotel_pay[13] = 9500000;
	hotel_pay[14] = 9500000;
	hotel_pay[15] = 10000000;
	hotel_pay[16] = 150000;//복지기금수령

	hotel_pay[17] = 1050000;
	hotel_pay[18] = 1100000;
	hotel_pay[19] = 1100000;
	hotel_pay[20] = 600000;

	hotel_pay[21] = 1150000;
	hotel_pay[22] = 1150000;
	hotel_pay[23] = 1200000;
	hotel_pay[24] = 0;//무인도

	hotel_pay[25] = 12700000;
	hotel_pay[26] = 1400000;
	hotel_pay[27] = 1400000;
	hotel_pay[28] = 1500000;

	hotel_pay[29] = 1500000;
	hotel_pay[30] = 0;
	hotel_pay[31] = 2000000;



	//building
	building_pay[0] = 0;
	building_pay[1] = 90000;
	building_pay[2] = 80000;
	building_pay[3] = 80000;
	building_pay[4] = 300000;

	building_pay[5] = 270000;
	building_pay[6] = 270000;
	building_pay[7] = 600000;
	building_pay[8] = 0;//무인도

	building_pay[9] = 450000;
	building_pay[10] = 450000;
	building_pay[11] = 500000;
	building_pay[12] = 300000;

	building_pay[13] = 500000;
	building_pay[14] = 500000;
	building_pay[15] = 550000;
	building_pay[16] = 150000;//복지기금수령

	building_pay[17] = 700000;
	building_pay[18] = 750000;
	building_pay[19] = 750000;
	building_pay[20] = 600000;

	building_pay[21] = 800000;
	building_pay[22] = 800000;
	building_pay[23] = 850000;
	building_pay[24] = 0;//무인도

	building_pay[25] = 900000;
	building_pay[26] = 1000000;
	building_pay[27] = 1000000;
	building_pay[28] = 1100000;

	building_pay[29] = 1100000;
	building_pay[30] = 0;
	building_pay[31] = 2000000;


	//villa
	villa_pay[0] = 0;
	villa_pay[1] = 10000;
	villa_pay[2] = 20000;
	villa_pay[3] = 20000;
	villa_pay[4] = 300000;

	villa_pay[5] = 30000;
	villa_pay[6] = 30000;
	villa_pay[7] = 40000;
	villa_pay[8] = 0;//무인도

	villa_pay[9] = 50000;
	villa_pay[10] = 60000;
	villa_pay[11] = 60000;
	villa_pay[12] = 300000;

	villa_pay[13] = 700000;
	villa_pay[14] = 700000;
	villa_pay[15] = 80000;
	villa_pay[16] = 150000;//복지기금 수령

	villa_pay[17] = 90000;
	villa_pay[18] = 100000;
	villa_pay[19] = 100000;
	villa_pay[20] = 600000;

	villa_pay[21] = 110000;
	villa_pay[22] = 110000;
	villa_pay[23] = 120000;
	villa_pay[24] = 0;//우주여행

	villa_pay[25] = 130000;
	villa_pay[26] = 150000;
	villa_pay[27] = 150000;
	villa_pay[28] = 170000;

	villa_pay[29] = 170000;
	villa_pay[30] = 0; //복지기금접수
	villa_pay[31] = 2000000;
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CChattingClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CChattingClientDlg::OnPaint()
{
	CPoint go;

	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트

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
		CDialog::OnPaint();
	}

	CClientDC dc(this);
	//CBrush myBrush(RGB(229, 245, 255));
	//dc.SelectObject(&myBrush);

	int j = 0;
	for (int i = 7; i >= 0; i--) { //아래
		dc.Rectangle(110 + i * 100, 810, 210 + i * 100, 910);

		location[j].x = i * 100 + 160;  //배열에 각 칸 위치정보 삽입
		location[j].y = 860;
		j++;
	}
	for (int i = 7; i >= 0; i--) { //왼쪽
		dc.Rectangle(10, 110 + i * 100, 110, 210 + i * 100);
		location[j].x = 60;
		location[j].y = i * 100 + 160;
		j++;
	}
	for (int i = 0; i < 8; i++) { //위
		dc.Rectangle(10 + i * 100, 10, 110 + i * 100, 110);
		location[j].x = i * 100 + 60;
		location[j].y = 60;
		j++;
	}
	for (int i = 0; i < 8; i++) { //오른쪽
		dc.Rectangle(810, 10 + i * 100, 910, 110 + i * 100);
		location[j].x = 860;
		location[j].y = i * 100 + 60;
		j++;
	}
	COLORREF c2[5] = { RGB(255, 150, 150), RGB(150, 150, 255), RGB(255, 255, 150), RGB(150, 150, 150) };

	for (int i = 0; i < 32; i++) {
		CString str;
		for (int j = 0; j < my_city.GetCount(); j++) {
			my_city.GetText(j, str);
			if (str.Compare(city[i]) == 0) {
				CBrush col2 = c2[me-1];
				dc.SelectObject(col2);
				dc.Rectangle(location[i].x - 50, location[i].y - 50, location[i].x + 50, location[i].y + 50);
			}
		}
		
		
	}
	for (int i = 0; i < 32; i++) { //게임판에 도시명 출력
		SetBkMode(dc, TRANSPARENT);
		CString tmp = city[i];
		if (city[i].GetLength() > 4)
			tmp = city[i].Left(4);
		dc.TextOutW(location[i].x - 45, location[i].y - 45, tmp);
	}

	

	//go = location[now];

	//dc.SelectObject(col);
	//dc.Ellipse(go.x - 20, go.y - 20, go.x + 20, go.y + 20);
	COLORREF c[5] = { RGB(255, 0, 0), RGB(0, 0, 255), RGB(255, 255, 0), RGB(255, 255, 255) };

	for (int i = 0; i < player.size(); i++) {
		go = location[player[i]];
		CBrush col = c[i];
		dc.SelectObject(col);
		//dc.Ellipse(go.x - 20 - (i + 1) * 20, go.y - 20 - (i + 1) * 20, go.x + 20 - (i + 1) * 20, go.y + 20 - (i + 1) * 20);
		if (i == 0) dc.Ellipse(go.x - 40, go.y - 40, go.x, go.y);
		else if (i == 1) dc.Ellipse(go.x, go.y - 40, go.x + 40, go.y);
		else if (i == 2) dc.Ellipse(go.x - 40, go.y, go.x, go.y + 40);
		else if (i == 3) dc.Ellipse(go.x, go.y, go.x, go.y + 40);
	}

	//CString str;
	//특정칸에 도달하면 건물 짓기(임시)
	//이후 DB와 연동해 now칸에 해당하는 도시정보 불러와서 비교할것
	//str.Format(L"%d에 도착했습니다. \n 대지료: %d  호텔: %d", now, 2500, 20000);
	/*
	if (MB_OK == AfxMessageBox(str)) {
		my_money.GetText(0, str);
		int m = _ttoi(str);
		m = m - 22500;
		my_money.ResetContent();
		str.Format(L"%d", m);
		my_money.AddString(str);
	}
	*/
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CChattingClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CChattingClientDlg::OnBnClickedButtonSend() //보내기버튼
{
	UpdateData(TRUE);

	//사용자가 입력한 메시지를 서버에 전송한다.
	//※ 전송된 메시지를 서버가 정상적으로 수신하면
	//   이를 다시 재전송 받게 되며 이때 리스트에 출력된다.(const char*)
	m_Socket.Send((LPCTSTR)m_strData, m_strData.GetLength()*2); //싱크 맞추려고, alphabet-> 한글

	m_strData = _T("");
	UpdateData(FALSE);
}

#include "ConnectDlg.h"
//서버 연결 버튼 눌렀을 때
void CChattingClientDlg::OnBnClickedButtonConnect()
{
  CConnectDlg  dlg;
  if(dlg.DoModal() == IDOK)
  {
	  PlaySoundW((LPCWSTR)MAKEINTRESOURCE(IDB_SOUND), NULL, SND_ASYNC | SND_RESOURCE);
	  	/////////////////////////////////////////////////////////////////////////
	//소켓을 생성하고 서버에 연결한다.
	m_Socket.Create();
	if(m_Socket.Connect(dlg.m_strAddress, 7000) == FALSE)
	{
		//서버 연결이 실패하였으므로 프로그램을 종료한다.
		AfxMessageBox(_T("Failed to connect server"));
		PostQuitMessage(0);
	}    
    // <보내기> 버튼 활성화
    m_ButtonSend.EnableWindow(TRUE); 
    // <서버 연결...> 버튼 비활성화
    m_ButtonConnect.EnableWindow(FALSE); 
  }
}

void CChattingClientDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}

//주사위 굴리기!
void CChattingClientDlg::OnBnClickedButton1()
{
	HWND hwnd = m_dice1.GetSafeHwnd();	// 컨트롤 핸들 얻기
	HDC hdc = ::GetDC(hwnd);	// 컨트롤 DC 얻기
	CImage imgFile;

	islandturn = 0;
	HWND hwnd1 = m_dice2.GetSafeHwnd();	// 컨트롤 핸들 얻기
	HDC hdc1 = ::GetDC(hwnd1);	// 컨트롤 DC 얻기
	CImage imgFile1;
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
	//제약조건...만약 당신이 무인도에 있다면?
	/*
	if (city[player[me - 1]] == L"무인도") {
		GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
		islandturn++;
		AfxMessageBox(L"당신은 지금 무인도에 갇혔있습니다.벗어나시려면 두 개의 주사위를 던졌을 때 같은 숫자가 나와야 합니다");
		srand((unsigned)time(NULL));
		int dice = rand() % 6 + 1;
		int dice2 = rand() % 6 + 1;
		int sum = dice + dice2;
		if (dice == 1) {
			imgFile.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP1); // 리소스 로드
		}
		if (dice == 2) {
			imgFile.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP2); // 리소스 로드
		}
		if (dice == 3) {
			imgFile.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP3); // 리소스 로드
		}
		if (dice == 4) {
			imgFile.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP4); // 리소스 로드
		}
		if (dice == 5) {
			imgFile.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP5); // 리소스 로드
		}
		if (dice == 6) {
			imgFile.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP6); // 리소스 로드
		}
		if (dice2 == 1) {
			imgFile1.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP1); // 리소스 로드
		}
		if (dice2 == 2) {
			imgFile1.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP2);
		}
		if (dice2 == 3) {
			imgFile1.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP3);
		}
		if (dice2 == 4) {
			imgFile1.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP4);
		}
		if (dice2 == 5) {
			imgFile1.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP5);
		}
		if (dice2 == 6) {
			imgFile1.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP6);
		}
		//아일랜드 숫자가 3이하일때,
		if (islandturn < 3) {
			if (dice != dice2) {
				if (turn + 1 == me) {
					CString tmp, str;
					dice_list.ResetContent();
					str.Format(L"%d %d", dice, dice2);
					dice_list.AddString(str);

					AfxMessageBox(L"아쉽군요 탈출하지 못했습니다.");

					sequence2 = 3;
					UpdateData(TRUE);

					m_strData.Format(_T("%d"), 0);
					//   이를 다시 재전송 받게 되며 이때 리스트에 출력된다.(const char*)
					m_Socket.Send((LPCTSTR)m_strData, m_strData.GetLength() * 2); //싱크 맞추려고, alphabet-> 한글
					m_strData = _T("");
					UpdateData(FALSE);
				}
			}
			//만약 주사위가 같은 숫자를 가르킨다면
			//dice == dice2
			else {
				if (turn + 1 == me) {
					CString tmp, str;
					dice_list.ResetContent();
					str.Format(L"%d %d", dice, dice2);
					dice_list.AddString(str);
					GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
					AfxMessageBox(L"탈출에 성공했습니다.");
					sequence2 = 3;
					UpdateData(TRUE);

					//사용자가 입력한 메시지를 서버에 전송한다.
					//※ 전송된 메시지를 서버가 정상적으로 수신하면

					m_strData.Format(_T("%d"), sum);
					//   이를 다시 재전송 받게 되며 이때 리스트에 출력된다.(const char*)
					m_Socket.Send((LPCTSTR)m_strData, m_strData.GetLength() * 2); //싱크 맞추려고, alphabet-> 한글
					m_strData = _T("");
					UpdateData(FALSE);
				}
			}
		}
		if(islandturn ==3)
		{
			if (turn + 1 == me) {
				CString tmp, str;
				dice_list.ResetContent();
				str.Format(L"%d %d", dice, dice2);
				dice_list.AddString(str);
				GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
				AfxMessageBox(L"탈출에 성공했습니다.");
				sequence2 = 3;
				UpdateData(TRUE);

				//사용자가 입력한 메시지를 서버에 전송한다.
				//※ 전송된 메시지를 서버가 정상적으로 수신하면

				m_strData.Format(_T("%d"), sum);
				//   이를 다시 재전송 받게 되며 이때 리스트에 출력된다.(const char*)
				m_Socket.Send((LPCTSTR)m_strData, m_strData.GetLength() * 2); //싱크 맞추려고, alphabet-> 한글
				m_strData = _T("");
				UpdateData(FALSE);
			}

		}
	}
	//무인도 탈출 조건 끝*/

	//무인도가 아닐때 시작
	//내 턴이고, 주사위 굴린 다음에?
	//내 턴이고 현재 위치가 무인도가 아닐 떄,
	//두 가지 경우가 있다.
	/*int dex=0;
				CString cs;
				CString css = pMain->city[pMain->player[pMain->turn]];

				dex=pMain->p_city.FindString(-1, css); //찾았다면 인덱스 번호 삽입
				
				if (dex!=-1) { //통행료를 모든 클라이언트에 전송
					pMain->p_price.GetText(dex, cs);
					Send((LPCTSTR)cs, cs.GetLength() * 2);
					//cs.Format(L"%d sell money", dex);
					AfxMessageBox(cs);
				}
				*/ //->이것과 같이 스트링에 비교를 해서 없는 경우 버튼 풀고, 있는 경우 버튼 막는다.
	//첫 번째는 스트링에 없을 때이다..

	/*else*/ {


	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
	srand((unsigned)time(NULL));
	int dice = rand() % 6 + 1;
	int dice2 = rand() % 6 + 1;
	int path_price = 0;
	int sum = dice + dice2;
	CString tmp, str, string;
	CBitmap bmp;

	
		if (turn + 1 == me) {
		dice_list.ResetContent();
		str.Format(L"%d %d", dice, dice2);
		dice_list.AddString(str);

		if (dice == 1) {
			imgFile.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP1); // 리소스 로드
		}
		if (dice == 2) {
			imgFile.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP2); // 리소스 로드
		}
		if (dice == 3) {
			imgFile.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP3); // 리소스 로드
		}
		if (dice == 4) {
			imgFile.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP4); // 리소스 로드
		}
		if (dice == 5) {
			imgFile.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP5); // 리소스 로드
		}
		if (dice == 6) {
			imgFile.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP6); // 리소스 로드
		}

		if (dice2 == 1) {
			imgFile1.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP1); // 리소스 로드
		}
		if (dice2 == 2) {
			imgFile1.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP2);
		}
		if (dice2 == 3) {
			imgFile1.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP3);
		}
		if (dice2 == 4) {
			imgFile1.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP4);
		}
		if (dice2 == 5) {
			imgFile1.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP5);
		}
		if (dice2 == 6) {
			imgFile1.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP6);
		}
		//주사위 이미지 끝
		sequence2 = 3;
		//turn++;
		UpdateData(TRUE);
		//사용자가 입력한 메시지를 서버에 전송한다.
		//※ 전송된 메시지를 서버가 정상적으로 수신하면

		m_strData.Format(_T("%d"), sum);
		//   이를 다시 재전송 받게 되며 이때 리스트에 출력된다.(const char*)
		m_Socket.Send((LPCTSTR)m_strData, m_strData.GetLength() * 2); //싱크 맞추려고, alphabet-> 한글
		m_strData = _T("");
		UpdateData(FALSE);
		//만약에 구입한 곳이 있으면, 못 구입하게 버튼을 막는다....?!!!!!!

		CString nowcity, start, bokjeopcity, boksucity, island, univjour, Concorde;
		start = L"출발";
		bokjeopcity = L"복지기금접수";
		boksucity = L"복지기금수령";
		island = L"무인도";
		univjour = L"우주여행";
		Concorde = L"콩코드여객기";

			const int next_loc = (player[me - 1] + sum) % 32;

			int dex = 0;
			CString cs;
			CString css = city[next_loc];

			dex = my_city.FindString(-1, css); //찾았다면 인덱스 번호 삽입

			if (dex == -1) { //통행료를 모든 클라이언트에 전송

			//cs.Format(L"%d sell money", dex);
				//AfxMessageBox(L"주인이 없는 땅입니다!");





				//0을 넘었기 때문에 돈 추가한다.
				if ((player[me - 1] + sum) >= 32) {
					my_money.GetText(0, str); //현재 내 돈
					int m = _ttoi(str);
					//은행에서 한바퀴 돌면 200000만원을 준다.
					m = m + 200000;
					my_money.ResetContent();
					str.Format(L"%d", m);
					my_money.AddString(str);
					//Invalidate();
				}
				if (city[next_loc].Compare(start) == 0) {
					GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);

					Invalidate();
				}
				if (city[next_loc].Compare(bokjeopcity) == 0) {
					GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
					my_money.GetText(0, str); //현재 내 돈
					int m = _ttoi(str);
					m = m - 150000;
					my_money.ResetContent();
					str.Format(L"%d", m);
					my_money.AddString(str);
					Invalidate();
				}
				if (city[next_loc].Compare(boksucity) == 0) {
					GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
					my_money.GetText(0, str); //현재 내 돈
					int m = _ttoi(str);
					//은행에서 한바퀴 돌면 200000만원을 준다.
					m = m + 150000;
					my_money.ResetContent();
					str.Format(L"%d", m);
					my_money.AddString(str);
					Invalidate();
				}
				if (city[next_loc].Compare(island) == 0) {
					AfxMessageBox(L"당신은 지금 무인도에 갖혔습니다.");
					GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
				}/*
				if (city[next_loc].Compare(univjour) == 0) {
					GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
					AfxMessageBox(L"우주여행! 플레이어가 출발점에 도착했습니다.");
					UpdateData(TRUE);
					//사용자가 입력한 메시지를 서버에 전송한다.
					//※ 전송된 메시지를 서버가 정상적으로 수신하면
					//현재 위치에서 원점으로 이동한다.
					m_strData.Format(_T("%d"), 8);
					//   이를 다시 재전송 받게 되며 이때 리스트에 출력된다.(const char*)
					m_Socket.Send((LPCTSTR)m_strData, m_strData.GetLength() * 2); //싱크 맞추려고, alphabet-> 한글
					my_money.GetText(0, str); //현재 내 돈
					int m = _ttoi(str);
					//은행에서 한바퀴 돌면 200000만원을 준다.
					m = m + 200000;
					my_money.ResetContent();
					str.Format(L"%d", m);
					my_money.AddString(str);
					m_strData = _T("");
					UpdateData(FALSE);
				}*/
				//콩코드 여객기 : 구매가 20만원, 통행료 30만원.
				if (city[next_loc].Compare(Concorde) == 0) {
					int dex = 0;
					CString cs;
					CString css = L"Concorde Plain";
					dex = my_structure.FindString(-1, css); //찾았다면 인덱스 번호 삽입
					if (dex != -1) { //통행료를 모든 클라이언트에 전송
						my_structure.GetText(dex, cs);
						//구입할 수 없음.
						GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
					}
					else {
						string = L"콩코드 여객기를 구매하시겠습니까?";
						GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
						UpdateData(TRUE);
						//스트링 비교

						if (IDYES == AfxMessageBox(string, MB_YESNO)) {
							my_money.GetText(0, str); //건설비용차감
							int m = _ttoi(str);
							m = m - 200000;
							my_money.ResetContent();
							str.Format(L"%d", m);
							my_money.AddString(str);
							path_price = 300000;
							Invalidate();

							str.Format(L"Concorde Plain");
							m_strData.Format(_T("buy Plain;%d"), path_price);
							my_city.AddString(city[player[me - 1]]);
							my_structure.AddString(str);
							str = "";
							m_Socket.Send((LPCTSTR)m_strData, m_strData.GetLength() * 2); //싱크 맞추려고, alphabet-> 한글
							m_strData = _T("");
							Invalidate();
						}

						else {
							AfxMessageBox(L"콩코드 여객기를 구입하지 않습니다.");
						}
						UpdateData(FALSE);
					}
				}//콩코드 여행기 닫기
			}
			else if (dex != -1) { 

			//cs.Format(L"%d sell money", dex);
				//AfxMessageBox(L"주인이 있는 땅입니다!");
				GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
			}

		}//무인도 아닌거 닫기
		else {
			AfxMessageBox(L"당신의 차례가 아님");
			GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
			imgFile.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP7); // 리소스 로드
			imgFile1.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP7); // 리소스 로드


		}
		
	}
	CRect rect;
	::GetWindowRect(hwnd, &rect);	// 컨트롤 크기 얻기
	::SetStretchBltMode(hdc, HALFTONE);	// HALFTONE모드로 설정해서 크기 축소로 인한 이미지 깨짐 현상 최소화
	imgFile.Draw(hdc, 0, 0, rect.Width(), rect.Height(), 0, 0, imgFile.GetWidth(), imgFile.GetHeight());


	CRect rect1;
	::GetWindowRect(hwnd1, &rect1);	// 컨트롤 크기 얻기
	::SetStretchBltMode(hdc1, HALFTONE);	// HALFTONE모드로 설정해서 크기 축소로 인한 이미지 깨짐 현상 최소화
	imgFile1.Draw(hdc1, 0, 0, rect1.Width(), rect1.Height(), 0, 0, imgFile1.GetWidth(), imgFile1.GetHeight());
}


void CChattingClientDlg::OnBnClickedButton3() //이후 턴수를 돌리는 타이밍을 조절해 자기턴일때만 건물사도록 조건 추가할것
{
	UpdateData(TRUE);
	int check1state = IsDlgButtonChecked(IDC_RADIO1);
	int check2state = IsDlgButtonChecked(IDC_RADIO2);
	int check3state = IsDlgButtonChecked(IDC_RADIO3);
	int check4state = IsDlgButtonChecked(IDC_RADIO4);
	CString str, str2;
	int sel = 0;
	int pay = 0;
	int path_price=0;

	if (check1state) {
		
		str2.Format(L"Hotel");
		sel = hotel_price[player[me - 1]];
		pay = hotel_pay[player[me - 1]];
		m_strData.Format( _T("buy hotel;%d"), pay);
	}
	if (check2state) {
		//m_strData = _T("buy building");
		str2.Format(L"Building");
		sel = build_price[player[me - 1]];
		pay = building_pay[player[me - 1]];
		m_strData.Format( _T("buy building;%d"), pay);
	}
	if (check3state) {
		//m_strData = _T("buy villa");
		str2.Format(L"Villa");
		sel = villa_price[player[me - 1]];
		pay = villa_pay[player[me - 1]];
		m_strData.Format( _T("buy villa;%d"), pay);
		
	}
	if (check4state) {
		//m_strData = _T("buy only card");
		str2.Format(L"Land");
		sel = land_price[player[me - 1]];
		pay = land_pay[player[me - 1]];
		m_strData.Format( _T("buy only card;%d"), pay);
	}
	//str2.Format(L"%d번 도시", city[player[me-1]]);
	//my_city.AddString(city[player[me - 1]]);
	//my_structure.AddString(str);

	str.Format(L"건설 비용은 %d원 입니다\n구입하시겠습니까?", sel);

	if (IDYES==AfxMessageBox(str, MB_YESNO)) {
		my_city.AddString(city[player[me - 1]]);
		my_structure.AddString(str2);

		my_money.GetText(0, str); //건설비용차감
		int m = _ttoi(str);
		m = m - sel;
		my_money.ResetContent();
		str.Format(L"%d", m);
		my_money.AddString(str);
		path_price = pay;  //임시로 통행료는 건설비용의 두배

		m_Socket.Send((LPCTSTR)m_strData, m_strData.GetLength() * 2); //싱크 맞추려고, alphabet-> 한글
		m_strData = _T("");
		Invalidate();
	}
	//사용자가 입력한 메시지를 서버에 전송한다.
	//※ 전송된 메시지를 서버가 정상적으로 수신하면
	//   이를 다시 재전송 받게 되며 이때 리스트에 출력된다.(const char*)
	//m_Socket.Send((LPCTSTR)m_strData, m_strData.GetLength() * 2); //싱크 맞추려고, alphabet-> 한글
	//m_strData = _T("");
	//Invalidate();

	UpdateData(FALSE);
	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

BOOL CChattingClientDlg::PreTranslateMessage(MSG* pMsg) //엔터키 누르면 메세지 전송
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_RETURN) {
		OnBnClickedButtonSend();
		return true;
	 }

	return CDialog::PreTranslateMessage(pMsg);
}


BOOL CChattingClientDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	SetCursor(LoadCursor(NULL, IDC_UPARROW));
	return TRUE;
}


BOOL CChattingClientDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rect;
	GetClientRect(&rect);
	CBrush myBrush(RGB(214, 230, 240)); // dialog background color.

	CBrush* pOld = pDC->SelectObject(&myBrush);
	BOOL bRes = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOld); // restore old brush
	return bRes; // CDialog::OnEraseBkgnd(pDC);
}


HBRUSH CChattingClientDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	if (nCtlColor == CTLCOLOR_STATIC)
	{
		pDC->SetBkColor(RGB(214, 230, 240));
	}
	if (nCtlColor == CTLCOLOR_BTN) {
		pDC->SetBkColor(RGB(214, 230, 240));
	}
		//pDC->SetBkMode(TRANSPARENT);

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}
