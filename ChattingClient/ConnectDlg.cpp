// ConnectDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ChattingClient.h"
#include "ConnectDlg.h"


// CConnectDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CConnectDlg, CDialog)

CConnectDlg::CConnectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConnectDlg::IDD, pParent)
{

}

CConnectDlg::~CConnectDlg()
{
}

void CConnectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CConnectDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CConnectDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CConnectDlg 메시지 처리기입니다.

BOOL CConnectDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	//이미 설정되어있는 곳인데, 나의 ip를 다시 입력해야 한다.

    SetDlgItemText(IDC_IPADDRESS1, _T("192.168.1.145"));

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CConnectDlg::OnBnClickedOk()
{
    //IP 컨트롤에 입력받은 서버의 IP 주소를 m_strAddress 변수에 저장
	GetDlgItemText(IDC_IPADDRESS1, m_strAddress); 
  	OnOK();
}
