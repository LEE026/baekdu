#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };


void bfs(vector<vector<int>>& paper, queue<pii>& next, int i, int j) {
	static queue<pii> q;
	q.push({ i,j });
	paper[i][j] = -1;
	int n = paper.size();
	int m = paper[0].size();

	//상온 체크
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + xd[k];
			int ny = y + yd[k];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;


			if (paper[nx][ny] >= 1) {
				paper[nx][ny]++;
				if (paper[nx][ny] == 3) {
					//다음에 녹을 치즈 체크
					next.push({ nx,ny });
					paper[nx][ny] = -1;
				}
			}
			else if(paper[nx][ny]==0)
			{
				q.push({ nx,ny });
				paper[nx][ny] = -1;
			}
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> paper(n, vector<int>(m));

	for (auto& i : paper) {
		for (auto& j : i) {
			cin >> j;
		}
	}

	queue<pii> q;
	q.push({ 0,0 });

	int cnt = 0;
	while (!q.empty())
	{
		int size = q.size();
		while (size--)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			bfs(paper, q, x, y);
		}
		cnt++;
	}

	cout << cnt - 1;



}