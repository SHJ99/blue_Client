// ConnectDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ChattingClient.h"
#include "ConnectDlg.h"


// CConnectDlg ��ȭ �����Դϴ�.

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


// CConnectDlg �޽��� ó�����Դϴ�.

BOOL CConnectDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	//�̹� �����Ǿ��ִ� ���ε�, ���� ip�� �ٽ� �Է��ؾ� �Ѵ�.

    SetDlgItemText(IDC_IPADDRESS1, _T("192.168.1.145"));

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CConnectDlg::OnBnClickedOk()
{
    //IP ��Ʈ�ѿ� �Է¹��� ������ IP �ּҸ� m_strAddress ������ ����
	GetDlgItemText(IDC_IPADDRESS1, m_strAddress); 
  	OnOK();
}
