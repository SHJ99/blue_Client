#pragma once

// CClientSocket ���� ����Դϴ�.

class CClientSocket : public CSocket
{
public:
	CClientSocket();
	virtual ~CClientSocket();
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	int n;
	int sequence;
};

