#pragma once


// CConnectDlg ��ȭ �����Դϴ�.

class CConnectDlg : public CDialog
{
	DECLARE_DYNAMIC(CConnectDlg)

public:
	CString  m_strAddress; 
	
	//vector<int>player;
	CConnectDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CConnectDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
