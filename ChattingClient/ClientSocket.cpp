// ClientSocket.cpp : 구현 파일입니다.
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


// CClientSocket 멤버 함수

void CClientSocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	//네트워크 입/출력을 중단하고 소켓을 닫는다.
	//셧다운
	ShutDown();
	//클로즈
	Close();

	CSocket::OnClose(nErrorCode);

	AfxMessageBox(_T("서버와 연결이 종료되었습니다."));
}

#include "ChattingClientDlg.h"
//다른 클라이언트가 쓴 메세지를 출력하는 함수.
void CClientSocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	char szBuffer[1024];
	CString tmp;
	::ZeroMemory(szBuffer, 1024);
	//실제로 데이터를 수신한다.
	if (Receive(szBuffer, 1024) > 0) {
		CChattingClientDlg* pMain = (CChattingClientDlg*)AfxGetMainWnd();

		if (isdigit(szBuffer[0])) { //isdigit 함수는 0~9 에 해당하는 ASCII 값이 입력으로 들어오면 0이 아닌 값(True)
			tmp.Format(_T("%s"), szBuffer);
			int d = _ttoi(tmp);

			if (d > 99 && d<1000) { //100번대는 플레이어 숫자와 번호, 1000 이상은 돈으로 간주한다.
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
			else if(d>1000){ //1000이상의 값 도착할시 내야하는 통행료로 간주. 내 돈에서 차감한다.
				int t = pMain->turn;
				if (t <= 0)
					pMain->player.size() - 1;
				else
					t = t - 1;

				//t = t % pMain->player.size();
				//const int cp = (pMain->turn + 1) % pMain->player.size(); //현재 턴인 플레이어 번호

				CString tcity = pMain->city[pMain->player[t]];
				//CString tcity = pMain->city[pMain->player[t]];
				int dex = pMain->my_city.FindString(-1, tcity); //내 땅이 아닐경우 -1 반환
				CString pmon, mon;

				int dex2 = pMain->my_city.FindString(-1, pMain->city[pMain->player[pMain->me - 1]]);
					//else if (dex!=-1) { //이번에 움직인 말이 내 땅에 있다면 통행료를 받아야 한다.
					//if (pMain->me != t + 1 /*&& dex==-1*/) {
				if (pMain->me != pMain->turn + 1 && dex2 == -1) {
					pmon.Format(L"통행료 %d원 획득", d);
					AfxMessageBox(pmon);
					pMain->my_money.GetText(0, mon);
					int m = _ttoi(mon);
					m = m + d;
					pMain->my_money.ResetContent();
					mon.Format(L"%d", m);
					pMain->my_money.AddString(mon);
					
				}

				else { //만약 움직인 말이 나라면 통행료를 지불해야 한다.+내땅이 아니라면       
			 //if (pMain->me == pMain->turn+1) {
					pmon.Format(L"통행료 %d원 지불 ", d);
					AfxMessageBox(pmon);
					pMain->my_money.GetText(0, mon); //통행료 차감
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
						pMain->player[pMain->turn] = 0; //시작점
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
			//수신한 메시지를 리스트에 출력한다.
			//CChattingClientDlg* pMain = (CChattingClientDlg*)AfxGetMainWnd();
			pMain->m_List.AddString(LPCTSTR(szBuffer));
			pMain->m_List.SetCurSel(pMain->m_List.GetCount() - 1);
		}
	}
	if(IDC_BUTTON1)
	CSocket::OnReceive(nErrorCode);
}
