#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };

int result = 11;

#define GOAL 'O'

void move(vector<string>& board,int cnt,
	int redx, int redy, int bluex, int bluey) {
	if (cnt >= result) return;
	if (board[bluex][bluey] == GOAL) return;
	if (board[redx][redy] == GOAL) {
		result = cnt;
		return;
	}
	

	for (int d = 0; d < 4; d++) {
		int nrx = redx, nry = redy;
		bool blue = false;
		while (board[nrx][nry] != '#'&& board[nrx][nry] != GOAL)
		{
			if (nrx==bluex&& nry==bluey) {
				blue = true;
			}
			nrx += xd[d];
			nry += yd[d];
		}
		if (board[nrx][nry] == '#') {
			nrx -= xd[d];
			nry -= yd[d];
		}

		int nbx = bluex, nby = bluey;
		while (board[nbx][nby] != '#' && board[nbx][nby] != GOAL)
		{
			nbx += xd[d];
			nby += yd[d];
		}
		if (board[nbx][nby] == '#') {
			nbx -= xd[d];
			nby -= yd[d];
		}

		if (board[nrx][nry] != GOAL&&nbx == nrx && nby == nry) {
			if (blue) {
				nrx -= xd[d];
				nry -= yd[d];
			}
			else
			{
				nbx -= xd[d];
				nby -= yd[d];
			}
		}
		if (nrx == redx && nry == redy && nbx == bluex && nby == bluey) continue;
		move(board, cnt + 1, nrx, nry, nbx, nby);
	}
	
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	vector<string> board(n);

	int redx, redy, bluex, bluey;
	for (int i = 0; i < n;i++) {
		cin >> board[i];
		for (int j = 0; j < m;j++) {
			if (board[i][j] == 'R') {
				redx = i;
				redy = j;
				board[i][j] = '.';
			}
			else if (board[i][j] == 'B') {
				bluex = i;
				bluey = j;
				board[i][j] = '.';
			}
		}
	}
	move(board, 0, redx, redy, bluex, bluey);
	if (result == 11) {
		result = -1;
	}
	cout << result;
}