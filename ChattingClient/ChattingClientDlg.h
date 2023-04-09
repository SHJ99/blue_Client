// ChattingClientDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#include<vector>
#include "ClientSocket.h"
#include <mmsystem.h> 
#pragma comment(lib, "winmm")
using namespace std;
// CChattingClientDlg 대화 상자
class CChattingClientDlg : public CDialog
{
// 생성입니다.
public:
	CClientSocket m_Socket;

	CChattingClientDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CHATTINGCLIENT_DIALOG };

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
	CListBox m_List;
	CString m_strData;
	afx_msg void OnBnClickedButtonSend();
	afx_msg void OnBnClickedButtonConnect();
	CButton m_ButtonSend;
	CButton m_ButtonConnect;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	// CButton// CButton
	CButton m_dice;
	CButton m_hotel;
	CButton m_building;
	CButton m_villa;
	CButton m_none;
	afx_msg void OnBnClickedButton3();
	CPoint location[32];
	CListBox dice_list;
	vector<int>player;
	int now;
	CListBox my_money;
	int turn;
	int me;
	int sequence2;
	CListBox my_city;
	CListBox my_structure;
	CString city[32];
	int land_price[32];
	int hotel_price[32];
	int build_price[32];
	int villa_price[32];
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CStatic m_dice1;
	CStatic m_dice2;
	int land_pay[32];
	int hotel_pay[32];
	int building_pay[32];
	int villa_pay[32];
	int islandturn;
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
