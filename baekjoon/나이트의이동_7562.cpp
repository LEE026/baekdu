#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int xd[] = { 2,2,-2,-2,1,-1,1,-1 };
int yd[] = { 1, -1,1,-1,2,2,-2,-2 };


int bfs(int n, pii start, pii end) {

	vector<vector<bool>> board(n, vector<bool>(n));
	queue<pii> q;
	q.push(start);
	board[start.first][start.second] = true;

	int cnt = 0;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {

			if (q.front() == end) {
				return cnt;
			}

			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 8; i++) {
				int nx = x + xd[i];
				int ny = y + yd[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (board[nx][ny]) continue;
				q.push({ nx,ny });
				board[nx][ny] = true;
			}
		}
		cnt++;
	}
	return -1;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		pii start, end;
		cin >> start.first >> start.second >> end.first >> end.second;

		cout << bfs(n, start, end) << "\n";

	}
}