// ChattingClient.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CChattingClientApp:
// �� Ŭ������ ������ ���ؼ��� ChattingClient.cpp�� �����Ͻʽÿ�.
//

class CChattingClientApp : public CWinApp
{
public:
	CChattingClientApp();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CChattingClientApp theApp;