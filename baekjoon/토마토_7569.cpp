#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int tomato[100][100][100];

struct point {
	int x;
	int y;
	int z;
};

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int m, n, h;
	int cnt = 0;
	cin >> m >> n >> h;

	queue<point> q;

	for (int k = 0; k < h; k++) {
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < m; i++) {
				cin >> tomato[k][j][i];
				if (tomato[k][j][i] == 1)
					q.push({ i,j,k });
				else if (tomato[k][j][i] == 0)
					cnt++;
			}
		}
	}

	int xd[] = { 1,-1,0,0,0,0 };
	int yd[] = { 0,0,1,-1,0,0 };
	int zd[] = { 0,0,0,0,1,-1 };

	int day = 0;
	while (!q.empty()&&cnt) {
		day++;
		int len = q.size();

		for (int i = 0; i < len; i++) {
			int x = q.front().x;
			int y = q.front().y;
			int z = q.front().z;
			q.pop();

			for (int j = 0; j < 6; j++) {
				int nx = x + xd[j];
				int ny = y + yd[j];
				int nz = z + zd[j];

				if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h)
					continue;

				if (tomato[nz][ny][nx] == 0) {
					cnt--;
					tomato[nz][ny][nx] = 1;
					q.push({ nx,ny,nz });
				}
			}
		}
	}

	if (cnt == 0)
		cout << day;
	else
		cout << -1;
}