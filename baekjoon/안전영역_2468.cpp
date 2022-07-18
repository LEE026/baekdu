#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int find(vector<int>& parent, int x) {
	if (parent[x] == -1) {
		return x;
	}
	return parent[x] = find(parent, parent[x]);
}

int Union(vector<int>& parent, int x, int y) {
	int px = find(parent, x);
	int py = find(parent, y);

	if (px == py) return 0;
	parent[py] = px;
	return 1;
}

int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int>> grid(n, vector<int>(n));
	priority_queue<pii> pq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
			pq.push({ grid[i][j], i * n + j });
		}
	}

	int maxv = 1;

	int cnt = 0;
	vector<int> parent(n * n, -1);
	for (int k = 100; k > 0; k--) {
		while (!pq.empty() && pq.top().first == k) {
			cnt++;
			int i = pq.top().second / n;
			int j = pq.top().second % n;
			pq.pop();
			for (int d = 0; d < 4; d++) {
				int nx = i + xd[d];
				int ny = j + yd[d];

				if (nx < 0 || n <= nx || ny < 0 || n <= ny) continue;
				if (grid[nx][ny] < k) continue;

				cnt -= Union(parent, i * n + j, nx * n + ny);
			}
		}
		maxv = max(maxv, cnt);
	}
	cout << maxv;
}