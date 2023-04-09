// ClientSocket.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ChattingClient.h"
#include "ClientSocket.h"


// CClientSocket

CClientSocket::CClientSocket()
{
	n = 0;
	sequence = 0;
}

CClientSocket::~CClientSocket()
{
}


// CClientSocket ��� �Լ�

void CClientSocket::OnClose(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	//��Ʈ��ũ ��/����� �ߴ��ϰ� ������ �ݴ´�.
	//�˴ٿ�
	ShutDown();
	//Ŭ����
	Close();

	CSocket::OnClose(nErrorCode);

	AfxMessageBox(_T("������ ������ ����Ǿ����ϴ�."));
}

#include "ChattingClientDlg.h"
//�ٸ� Ŭ���̾�Ʈ�� �� �޼����� ����ϴ� �Լ�.
void CClientSocket::OnReceive(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	char szBuffer[1024];
	CString tmp;
	::ZeroMemory(szBuffer, 1024);
	//������ �����͸� �����Ѵ�.
	if (Receive(szBuffer, 1024) > 0) {
		CChattingClientDlg* pMain = (CChattingClientDlg*)AfxGetMainWnd();

		if (isdigit(szBuffer[0])) { //isdigit �Լ��� 0~9 �� �ش��ϴ� ASCII ���� �Է����� ������ 0�� �ƴ� ��(True)
			tmp.Format(_T("%s"), szBuffer);
			int d = _ttoi(tmp);

			if (d > 99 && d<1000) { //100����� �÷��̾� ���ڿ� ��ȣ, 1000 �̻��� ������ �����Ѵ�.
				if (pMain->sequence2 == 0) {
					pMain->me = d/100;
					CString s = L"";
					s.Format(L"%d", d);
					//AfxMessageBox(s);
					for (int i = 0; i < pMain->me; i++) {
						pMain->player.push_back(0);
						pMain->Invalidate();
					}

					pMain->sequence2++;
					pMain->Invalidate();
				}
				else{
					pMain->player.push_back(0);
					pMain->Invalidate();
				}
			}
			else if(d>1000){ //1000�̻��� �� �����ҽ� �����ϴ� ������ ����. �� ������ �����Ѵ�.
				int t = pMain->turn;
				if (t <= 0)
					pMain->player.size() - 1;
				else
					t = t - 1;

				//t = t % pMain->player.size();
				//const int cp = (pMain->turn + 1) % pMain->player.size(); //���� ���� �÷��̾� ��ȣ

				CString tcity = pMain->city[pMain->player[t]];
				//CString tcity = pMain->city[pMain->player[t]];
				int dex = pMain->my_city.FindString(-1, tcity); //�� ���� �ƴҰ�� -1 ��ȯ
				CString pmon, mon;

				int dex2 = pMain->my_city.FindString(-1, pMain->city[pMain->player[pMain->me - 1]]);
					//else if (dex!=-1) { //�̹��� ������ ���� �� ���� �ִٸ� ����Ḧ �޾ƾ� �Ѵ�.
					//if (pMain->me != t + 1 /*&& dex==-1*/) {
				if (pMain->me != pMain->turn + 1 && dex2 == -1) {
					pmon.Format(L"����� %d�� ȹ��", d);
					AfxMessageBox(pmon);
					pMain->my_money.GetText(0, mon);
					int m = _ttoi(mon);
					m = m + d;
					pMain->my_money.ResetContent();
					mon.Format(L"%d", m);
					pMain->my_money.AddString(mon);
					
				}

				else { //���� ������ ���� ����� ����Ḧ �����ؾ� �Ѵ�.+������ �ƴ϶��       
			 //if (pMain->me == pMain->turn+1) {
					pmon.Format(L"����� %d�� ���� ", d);
					AfxMessageBox(pmon);
					pMain->my_money.GetText(0, mon); //����� ����
					int m = _ttoi(mon);
					m = m - d;
					pMain->my_money.ResetContent();
					mon.Format(L"%d", m);
					pMain->my_money.AddString(mon);

				}
				
			}
			else {//tmp.Format(_T("%s"), szBuffer);
				//int d = _ttoi(tmp);
				//CString s;
				//s.Format(L"%d", d);
				//AfxMessageBox(s);
				
				for (int i = 0; i < d; i++) {
					pMain->player[pMain->turn]++;
					if (pMain->player[pMain->turn] > 31)
						pMain->player[pMain->turn] = 0; //������
				}
				//pMain->m_List.AddString(tmp);

				if (pMain->turn + 1 >= pMain->player.size())
					pMain->turn = 0;
				else
					pMain->turn++;

				pMain->Invalidate();
			}

		}
		else{
			//������ �޽����� ����Ʈ�� ����Ѵ�.
			//CChattingClientDlg* pMain = (CChattingClientDlg*)AfxGetMainWnd();
			pMain->m_List.AddString(LPCTSTR(szBuffer));
			pMain->m_List.SetCurSel(pMain->m_List.GetCount() - 1);
		}
	}
	if(IDC_BUTTON1)
	CSocket::OnReceive(nErrorCode);
}
