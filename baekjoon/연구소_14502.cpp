#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
int xd[] = { 1,-1,0,0 };
int yd[] = { 0,0,1,-1 };

typedef pair<int, int> pii;

int bfs(vector<vector<int>> rooms, queue<pii> q) {
	int cnt = 0;
	int n = rooms.size();
	int m = rooms[0].size();
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = x + xd[d];
			int ny = y + yd[d];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			if (rooms[nx][ny] == 0) {
				rooms[nx][ny] = 2;
				q.push({ nx,ny });
				cnt++;
			}
		}
	}
	return cnt;
}

int makewall(vector<vector<int>>& rooms, queue<pii>& q, int total, int si, int cnt) {
	if (cnt == 3) {
		return total - bfs(rooms, q);
	}
	int n = rooms.size();
	int m = rooms[0].size();

	int maxv = 0;
	for (int i = si; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (rooms[i][j] == 0) {
				rooms[i][j] = 1;
				maxv = max(maxv, makewall(rooms, q, total - 1, i, cnt + 1));
				rooms[i][j] = 0;
			}
		}
	}
	return maxv;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> rooms(n, vector<int>(m));

	queue<pii> q;
	int total = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> rooms[i][j];
			if (rooms[i][j] == 0) {
				total++;
			}
			else if (rooms[i][j] == 2) {
				q.push({ i,j });
			}
		}
	}

	cout << makewall(rooms, q, total, 0, 0);
}