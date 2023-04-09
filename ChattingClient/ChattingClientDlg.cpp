// ChattingClientDlg.cpp : ���� ����
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


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CChattingClientDlg ��ȭ ����




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


// CChattingClientDlg �޽��� ó����

BOOL CChattingClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	CString money;
	now = 0;
	sequence2 = 0;
	turn = 0;
	me = 0;
	
	money.Format(L"%d", 10000000);
	my_money.AddString(money);//���۱ݾ� �鸸��

	CString str; //city�迭�� ���ø� �ֱ�
	str.Format(L"���");
	city[0] = str;
	str.Format(L"Ÿ�̺���");
	city[1] = str;
	str.Format(L"����¡");
	city[2] = str;
	str.Format(L"���Ҷ�");
	city[3] = str;
	str.Format(L"���ֵ�");
	city[4] = str;
	str.Format(L"�̰�����");
	city[5] = str;
	str.Format(L"ī�̷�");
	city[6] = str;
	str.Format(L"�̽�ź��");
	city[7] = str;
	str.Format(L"���ε�");
	city[8] = str;
	str.Format(L"���׳�");
	city[9] = str;
	str.Format(L"�����ϰ�");
	city[10] = str;
	str.Format(L"����Ȧ��");
	city[11] = str;
	str.Format(L"���ڵ忩����");
	city[12] = str;
	str.Format(L"����");
	city[13] = str;
	str.Format(L"������");
	city[14] = str;
	str.Format(L"��Ÿ��");
	city[15] = str;
	str.Format(L"������ݼ���");
	city[16] = str;
	str.Format(L"�ο��뽺���̷���");
	city[17] = str;
	str.Format(L"���Ŀ��");
	city[18] = str;
	str.Format(L"�õ��");
	city[19] = str;
	str.Format(L"�λ�");
	city[20] = str;
	str.Format(L"�Ͽ���");
	city[21] = str;
	str.Format(L"������");
	city[22] = str;
	str.Format(L"���帮��");
	city[23] = str;
	str.Format(L"���ֿ���");
	city[24] = str;
	str.Format(L"����");
	city[25] = str;
	str.Format(L"�ĸ�");
	city[26] = str;
	str.Format(L"�θ�");
	city[27] = str;
	str.Format(L"����");
	city[28] = str;
	str.Format(L"����");
	city[29] = str;
	str.Format(L"�����������");
	city[30] = str;
	str.Format(L"����");
	city[31] = str;

	for (int i = 0; i < 32; i++) { //�Ǽ���� �ʱ�ȭ. ���ε��� ������� ���� 0
		land_price[i]=0;
		hotel_price[i]=0;
		build_price[i]=0;
		villa_price[i]=0;
	}
	for (int i = 1; i < 8; i++) { //�� ���� �Ǽ������ ��� ����.
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
	land_price[4] = 200000; //���ֵ�
	land_price[12] = 200000; //���ڵ� ������
	land_price[20] = 200000; //�λ�
	land_price[30] = 150000; //�����������
	land_price[31] = 1000000; //����
	land_pay[0] = 0;
	land_pay[1] = 2000;
	land_pay[2] = 2000;
	land_pay[3] = 4000;
	land_pay[4] = 300000;

	land_pay[5] = 6000;
	land_pay[6] = 6000;
	land_pay[7] = 8000;
	land_pay[8] = 0;//���ε�

	land_pay[9] = 10000;
	land_pay[10] = 10000;
	land_pay[11] = 12000;
	land_pay[12] = 300000;

	land_pay[13] = 14000;
	land_pay[14] = 14000;
	land_pay[15] = 16000;
	land_pay[16] = 150000;//������ݼ���

	land_pay[17] = 18000;
	land_pay[18] = 20000;
	land_pay[19] = 20000;
	land_pay[20] = 600000;

	land_pay[21] = 22000;
	land_pay[22] = 22000;
	land_pay[23] = 24000;
	land_pay[24] = 0;//���ֿ���

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
	hotel_pay[8] = 0;//���ε�

	hotel_pay[9] = 750000;
	hotel_pay[10] = 750000;
	hotel_pay[11] = 900000;
	hotel_pay[12] = 300000;

	hotel_pay[13] = 9500000;
	hotel_pay[14] = 9500000;
	hotel_pay[15] = 10000000;
	hotel_pay[16] = 150000;//������ݼ���

	hotel_pay[17] = 1050000;
	hotel_pay[18] = 1100000;
	hotel_pay[19] = 1100000;
	hotel_pay[20] = 600000;

	hotel_pay[21] = 1150000;
	hotel_pay[22] = 1150000;
	hotel_pay[23] = 1200000;
	hotel_pay[24] = 0;//���ε�

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
	building_pay[8] = 0;//���ε�

	building_pay[9] = 450000;
	building_pay[10] = 450000;
	building_pay[11] = 500000;
	building_pay[12] = 300000;

	building_pay[13] = 500000;
	building_pay[14] = 500000;
	building_pay[15] = 550000;
	building_pay[16] = 150000;//������ݼ���

	building_pay[17] = 700000;
	building_pay[18] = 750000;
	building_pay[19] = 750000;
	building_pay[20] = 600000;

	building_pay[21] = 800000;
	building_pay[22] = 800000;
	building_pay[23] = 850000;
	building_pay[24] = 0;//���ε�

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
	villa_pay[8] = 0;//���ε�

	villa_pay[9] = 50000;
	villa_pay[10] = 60000;
	villa_pay[11] = 60000;
	villa_pay[12] = 300000;

	villa_pay[13] = 700000;
	villa_pay[14] = 700000;
	villa_pay[15] = 80000;
	villa_pay[16] = 150000;//������� ����

	villa_pay[17] = 90000;
	villa_pay[18] = 100000;
	villa_pay[19] = 100000;
	villa_pay[20] = 600000;

	villa_pay[21] = 110000;
	villa_pay[22] = 110000;
	villa_pay[23] = 120000;
	villa_pay[24] = 0;//���ֿ���

	villa_pay[25] = 130000;
	villa_pay[26] = 150000;
	villa_pay[27] = 150000;
	villa_pay[28] = 170000;

	villa_pay[29] = 170000;
	villa_pay[30] = 0; //�����������
	villa_pay[31] = 2000000;
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CChattingClientDlg::OnPaint()
{
	CPoint go;

	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
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
	for (int i = 7; i >= 0; i--) { //�Ʒ�
		dc.Rectangle(110 + i * 100, 810, 210 + i * 100, 910);

		location[j].x = i * 100 + 160;  //�迭�� �� ĭ ��ġ���� ����
		location[j].y = 860;
		j++;
	}
	for (int i = 7; i >= 0; i--) { //����
		dc.Rectangle(10, 110 + i * 100, 110, 210 + i * 100);
		location[j].x = 60;
		location[j].y = i * 100 + 160;
		j++;
	}
	for (int i = 0; i < 8; i++) { //��
		dc.Rectangle(10 + i * 100, 10, 110 + i * 100, 110);
		location[j].x = i * 100 + 60;
		location[j].y = 60;
		j++;
	}
	for (int i = 0; i < 8; i++) { //������
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
	for (int i = 0; i < 32; i++) { //�����ǿ� ���ø� ���
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
	//Ư��ĭ�� �����ϸ� �ǹ� ����(�ӽ�)
	//���� DB�� ������ nowĭ�� �ش��ϴ� �������� �ҷ��ͼ� ���Ұ�
	//str.Format(L"%d�� �����߽��ϴ�. \n ������: %d  ȣ��: %d", now, 2500, 20000);
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

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CChattingClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CChattingClientDlg::OnBnClickedButtonSend() //�������ư
{
	UpdateData(TRUE);

	//����ڰ� �Է��� �޽����� ������ �����Ѵ�.
	//�� ���۵� �޽����� ������ ���������� �����ϸ�
	//   �̸� �ٽ� ������ �ް� �Ǹ� �̶� ����Ʈ�� ��µȴ�.(const char*)
	m_Socket.Send((LPCTSTR)m_strData, m_strData.GetLength()*2); //��ũ ���߷���, alphabet-> �ѱ�

	m_strData = _T("");
	UpdateData(FALSE);
}

#include "ConnectDlg.h"
//���� ���� ��ư ������ ��
void CChattingClientDlg::OnBnClickedButtonConnect()
{
  CConnectDlg  dlg;
  if(dlg.DoModal() == IDOK)
  {
	  PlaySoundW((LPCWSTR)MAKEINTRESOURCE(IDB_SOUND), NULL, SND_ASYNC | SND_RESOURCE);
	  	/////////////////////////////////////////////////////////////////////////
	//������ �����ϰ� ������ �����Ѵ�.
	m_Socket.Create();
	if(m_Socket.Connect(dlg.m_strAddress, 7000) == FALSE)
	{
		//���� ������ �����Ͽ����Ƿ� ���α׷��� �����Ѵ�.
		AfxMessageBox(_T("Failed to connect server"));
		PostQuitMessage(0);
	}    
    // <������> ��ư Ȱ��ȭ
    m_ButtonSend.EnableWindow(TRUE); 
    // <���� ����...> ��ư ��Ȱ��ȭ
    m_ButtonConnect.EnableWindow(FALSE); 
  }
}

void CChattingClientDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}

//�ֻ��� ������!
void CChattingClientDlg::OnBnClickedButton1()
{
	HWND hwnd = m_dice1.GetSafeHwnd();	// ��Ʈ�� �ڵ� ���
	HDC hdc = ::GetDC(hwnd);	// ��Ʈ�� DC ���
	CImage imgFile;

	islandturn = 0;
	HWND hwnd1 = m_dice2.GetSafeHwnd();	// ��Ʈ�� �ڵ� ���
	HDC hdc1 = ::GetDC(hwnd1);	// ��Ʈ�� DC ���
	CImage imgFile1;
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
	//��������...���� ����� ���ε��� �ִٸ�?
	/*
	if (city[player[me - 1]] == L"���ε�") {
		GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
		islandturn++;
		AfxMessageBox(L"����� ���� ���ε��� �����ֽ��ϴ�.����÷��� �� ���� �ֻ����� ������ �� ���� ���ڰ� ���;� �մϴ�");
		srand((unsigned)time(NULL));
		int dice = rand() % 6 + 1;
		int dice2 = rand() % 6 + 1;
		int sum = dice + dice2;
		if (dice == 1) {
			imgFile.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP1); // ���ҽ� �ε�
		}
		if (dice == 2) {
			imgFile.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP2); // ���ҽ� �ε�
		}
		if (dice == 3) {
			imgFile.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP3); // ���ҽ� �ε�
		}
		if (dice == 4) {
			imgFile.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP4); // ���ҽ� �ε�
		}
		if (dice == 5) {
			imgFile.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP5); // ���ҽ� �ε�
		}
		if (dice == 6) {
			imgFile.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP6); // ���ҽ� �ε�
		}
		if (dice2 == 1) {
			imgFile1.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP1); // ���ҽ� �ε�
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
		//���Ϸ��� ���ڰ� 3�����϶�,
		if (islandturn < 3) {
			if (dice != dice2) {
				if (turn + 1 == me) {
					CString tmp, str;
					dice_list.ResetContent();
					str.Format(L"%d %d", dice, dice2);
					dice_list.AddString(str);

					AfxMessageBox(L"�ƽ����� Ż������ ���߽��ϴ�.");

					sequence2 = 3;
					UpdateData(TRUE);

					m_strData.Format(_T("%d"), 0);
					//   �̸� �ٽ� ������ �ް� �Ǹ� �̶� ����Ʈ�� ��µȴ�.(const char*)
					m_Socket.Send((LPCTSTR)m_strData, m_strData.GetLength() * 2); //��ũ ���߷���, alphabet-> �ѱ�
					m_strData = _T("");
					UpdateData(FALSE);
				}
			}
			//���� �ֻ����� ���� ���ڸ� ����Ų�ٸ�
			//dice == dice2
			else {
				if (turn + 1 == me) {
					CString tmp, str;
					dice_list.ResetContent();
					str.Format(L"%d %d", dice, dice2);
					dice_list.AddString(str);
					GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
					AfxMessageBox(L"Ż�⿡ �����߽��ϴ�.");
					sequence2 = 3;
					UpdateData(TRUE);

					//����ڰ� �Է��� �޽����� ������ �����Ѵ�.
					//�� ���۵� �޽����� ������ ���������� �����ϸ�

					m_strData.Format(_T("%d"), sum);
					//   �̸� �ٽ� ������ �ް� �Ǹ� �̶� ����Ʈ�� ��µȴ�.(const char*)
					m_Socket.Send((LPCTSTR)m_strData, m_strData.GetLength() * 2); //��ũ ���߷���, alphabet-> �ѱ�
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
				AfxMessageBox(L"Ż�⿡ �����߽��ϴ�.");
				sequence2 = 3;
				UpdateData(TRUE);

				//����ڰ� �Է��� �޽����� ������ �����Ѵ�.
				//�� ���۵� �޽����� ������ ���������� �����ϸ�

				m_strData.Format(_T("%d"), sum);
				//   �̸� �ٽ� ������ �ް� �Ǹ� �̶� ����Ʈ�� ��µȴ�.(const char*)
				m_Socket.Send((LPCTSTR)m_strData, m_strData.GetLength() * 2); //��ũ ���߷���, alphabet-> �ѱ�
				m_strData = _T("");
				UpdateData(FALSE);
			}

		}
	}
	//���ε� Ż�� ���� ��*/

	//���ε��� �ƴҶ� ����
	//�� ���̰�, �ֻ��� ���� ������?
	//�� ���̰� ���� ��ġ�� ���ε��� �ƴ� ��,
	//�� ���� ��찡 �ִ�.
	/*int dex=0;
				CString cs;
				CString css = pMain->city[pMain->player[pMain->turn]];

				dex=pMain->p_city.FindString(-1, css); //ã�Ҵٸ� �ε��� ��ȣ ����
				
				if (dex!=-1) { //����Ḧ ��� Ŭ���̾�Ʈ�� ����
					pMain->p_price.GetText(dex, cs);
					Send((LPCTSTR)cs, cs.GetLength() * 2);
					//cs.Format(L"%d sell money", dex);
					AfxMessageBox(cs);
				}
				*/ //->�̰Ͱ� ���� ��Ʈ���� �񱳸� �ؼ� ���� ��� ��ư Ǯ��, �ִ� ��� ��ư ���´�.
	//ù ��°�� ��Ʈ���� ���� ���̴�..

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
			imgFile.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP1); // ���ҽ� �ε�
		}
		if (dice == 2) {
			imgFile.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP2); // ���ҽ� �ε�
		}
		if (dice == 3) {
			imgFile.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP3); // ���ҽ� �ε�
		}
		if (dice == 4) {
			imgFile.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP4); // ���ҽ� �ε�
		}
		if (dice == 5) {
			imgFile.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP5); // ���ҽ� �ε�
		}
		if (dice == 6) {
			imgFile.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP6); // ���ҽ� �ε�
		}

		if (dice2 == 1) {
			imgFile1.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP1); // ���ҽ� �ε�
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
		//�ֻ��� �̹��� ��
		sequence2 = 3;
		//turn++;
		UpdateData(TRUE);
		//����ڰ� �Է��� �޽����� ������ �����Ѵ�.
		//�� ���۵� �޽����� ������ ���������� �����ϸ�

		m_strData.Format(_T("%d"), sum);
		//   �̸� �ٽ� ������ �ް� �Ǹ� �̶� ����Ʈ�� ��µȴ�.(const char*)
		m_Socket.Send((LPCTSTR)m_strData, m_strData.GetLength() * 2); //��ũ ���߷���, alphabet-> �ѱ�
		m_strData = _T("");
		UpdateData(FALSE);
		//���࿡ ������ ���� ������, �� �����ϰ� ��ư�� ���´�....?!!!!!!

		CString nowcity, start, bokjeopcity, boksucity, island, univjour, Concorde;
		start = L"���";
		bokjeopcity = L"�����������";
		boksucity = L"������ݼ���";
		island = L"���ε�";
		univjour = L"���ֿ���";
		Concorde = L"���ڵ忩����";

			const int next_loc = (player[me - 1] + sum) % 32;

			int dex = 0;
			CString cs;
			CString css = city[next_loc];

			dex = my_city.FindString(-1, css); //ã�Ҵٸ� �ε��� ��ȣ ����

			if (dex == -1) { //����Ḧ ��� Ŭ���̾�Ʈ�� ����

			//cs.Format(L"%d sell money", dex);
				//AfxMessageBox(L"������ ���� ���Դϴ�!");





				//0�� �Ѿ��� ������ �� �߰��Ѵ�.
				if ((player[me - 1] + sum) >= 32) {
					my_money.GetText(0, str); //���� �� ��
					int m = _ttoi(str);
					//���࿡�� �ѹ��� ���� 200000������ �ش�.
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
					my_money.GetText(0, str); //���� �� ��
					int m = _ttoi(str);
					m = m - 150000;
					my_money.ResetContent();
					str.Format(L"%d", m);
					my_money.AddString(str);
					Invalidate();
				}
				if (city[next_loc].Compare(boksucity) == 0) {
					GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
					my_money.GetText(0, str); //���� �� ��
					int m = _ttoi(str);
					//���࿡�� �ѹ��� ���� 200000������ �ش�.
					m = m + 150000;
					my_money.ResetContent();
					str.Format(L"%d", m);
					my_money.AddString(str);
					Invalidate();
				}
				if (city[next_loc].Compare(island) == 0) {
					AfxMessageBox(L"����� ���� ���ε��� �������ϴ�.");
					GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
				}/*
				if (city[next_loc].Compare(univjour) == 0) {
					GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
					AfxMessageBox(L"���ֿ���! �÷��̾ ������� �����߽��ϴ�.");
					UpdateData(TRUE);
					//����ڰ� �Է��� �޽����� ������ �����Ѵ�.
					//�� ���۵� �޽����� ������ ���������� �����ϸ�
					//���� ��ġ���� �������� �̵��Ѵ�.
					m_strData.Format(_T("%d"), 8);
					//   �̸� �ٽ� ������ �ް� �Ǹ� �̶� ����Ʈ�� ��µȴ�.(const char*)
					m_Socket.Send((LPCTSTR)m_strData, m_strData.GetLength() * 2); //��ũ ���߷���, alphabet-> �ѱ�
					my_money.GetText(0, str); //���� �� ��
					int m = _ttoi(str);
					//���࿡�� �ѹ��� ���� 200000������ �ش�.
					m = m + 200000;
					my_money.ResetContent();
					str.Format(L"%d", m);
					my_money.AddString(str);
					m_strData = _T("");
					UpdateData(FALSE);
				}*/
				//���ڵ� ������ : ���Ű� 20����, ����� 30����.
				if (city[next_loc].Compare(Concorde) == 0) {
					int dex = 0;
					CString cs;
					CString css = L"Concorde Plain";
					dex = my_structure.FindString(-1, css); //ã�Ҵٸ� �ε��� ��ȣ ����
					if (dex != -1) { //����Ḧ ��� Ŭ���̾�Ʈ�� ����
						my_structure.GetText(dex, cs);
						//������ �� ����.
						GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
					}
					else {
						string = L"���ڵ� �����⸦ �����Ͻðڽ��ϱ�?";
						GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
						UpdateData(TRUE);
						//��Ʈ�� ��

						if (IDYES == AfxMessageBox(string, MB_YESNO)) {
							my_money.GetText(0, str); //�Ǽ��������
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
							m_Socket.Send((LPCTSTR)m_strData, m_strData.GetLength() * 2); //��ũ ���߷���, alphabet-> �ѱ�
							m_strData = _T("");
							Invalidate();
						}

						else {
							AfxMessageBox(L"���ڵ� �����⸦ �������� �ʽ��ϴ�.");
						}
						UpdateData(FALSE);
					}
				}//���ڵ� ����� �ݱ�
			}
			else if (dex != -1) { 

			//cs.Format(L"%d sell money", dex);
				//AfxMessageBox(L"������ �ִ� ���Դϴ�!");
				GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
			}

		}//���ε� �ƴѰ� �ݱ�
		else {
			AfxMessageBox(L"����� ���ʰ� �ƴ�");
			GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
			imgFile.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP7); // ���ҽ� �ε�
			imgFile1.LoadFromResource(::AfxGetInstanceHandle(), IDB_BITMAP7); // ���ҽ� �ε�


		}
		
	}
	CRect rect;
	::GetWindowRect(hwnd, &rect);	// ��Ʈ�� ũ�� ���
	::SetStretchBltMode(hdc, HALFTONE);	// HALFTONE���� �����ؼ� ũ�� ��ҷ� ���� �̹��� ���� ���� �ּ�ȭ
	imgFile.Draw(hdc, 0, 0, rect.Width(), rect.Height(), 0, 0, imgFile.GetWidth(), imgFile.GetHeight());


	CRect rect1;
	::GetWindowRect(hwnd1, &rect1);	// ��Ʈ�� ũ�� ���
	::SetStretchBltMode(hdc1, HALFTONE);	// HALFTONE���� �����ؼ� ũ�� ��ҷ� ���� �̹��� ���� ���� �ּ�ȭ
	imgFile1.Draw(hdc1, 0, 0, rect1.Width(), rect1.Height(), 0, 0, imgFile1.GetWidth(), imgFile1.GetHeight());
}


void CChattingClientDlg::OnBnClickedButton3() //���� �ϼ��� ������ Ÿ�̹��� ������ �ڱ����϶��� �ǹ��絵�� ���� �߰��Ұ�
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
	//str2.Format(L"%d�� ����", city[player[me-1]]);
	//my_city.AddString(city[player[me - 1]]);
	//my_structure.AddString(str);

	str.Format(L"�Ǽ� ����� %d�� �Դϴ�\n�����Ͻðڽ��ϱ�?", sel);

	if (IDYES==AfxMessageBox(str, MB_YESNO)) {
		my_city.AddString(city[player[me - 1]]);
		my_structure.AddString(str2);

		my_money.GetText(0, str); //�Ǽ��������
		int m = _ttoi(str);
		m = m - sel;
		my_money.ResetContent();
		str.Format(L"%d", m);
		my_money.AddString(str);
		path_price = pay;  //�ӽ÷� ������ �Ǽ������ �ι�

		m_Socket.Send((LPCTSTR)m_strData, m_strData.GetLength() * 2); //��ũ ���߷���, alphabet-> �ѱ�
		m_strData = _T("");
		Invalidate();
	}
	//����ڰ� �Է��� �޽����� ������ �����Ѵ�.
	//�� ���۵� �޽����� ������ ���������� �����ϸ�
	//   �̸� �ٽ� ������ �ް� �Ǹ� �̶� ����Ʈ�� ��µȴ�.(const char*)
	//m_Socket.Send((LPCTSTR)m_strData, m_strData.GetLength() * 2); //��ũ ���߷���, alphabet-> �ѱ�
	//m_strData = _T("");
	//Invalidate();

	UpdateData(FALSE);
	
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

BOOL CChattingClientDlg::PreTranslateMessage(MSG* pMsg) //����Ű ������ �޼��� ����
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->wParam == VK_RETURN) {
		OnBnClickedButtonSend();
		return true;
	 }

	return CDialog::PreTranslateMessage(pMsg);
}


BOOL CChattingClientDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	SetCursor(LoadCursor(NULL, IDC_UPARROW));
	return TRUE;
}


BOOL CChattingClientDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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

	// TODO:  ���⼭ DC�� Ư���� �����մϴ�.
	if (nCtlColor == CTLCOLOR_STATIC)
	{
		pDC->SetBkColor(RGB(214, 230, 240));
	}
	if (nCtlColor == CTLCOLOR_BTN) {
		pDC->SetBkColor(RGB(214, 230, 240));
	}
		//pDC->SetBkMode(TRANSPARENT);

	// TODO:  �⺻���� �������� ������ �ٸ� �귯�ø� ��ȯ�մϴ�.
	return hbr;
}
