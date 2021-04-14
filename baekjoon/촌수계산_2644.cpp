#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	int x, y;
	int m;
	cin >> n;
	vector<vector<int>> num(n);
	vector<bool> visit(n,false);
	cin >> x >> y;
	cin >> m;
	int v1, v2;
	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2;
		num[v1-1].push_back(v2-1);
		num[v2-1].push_back(v1-1);
	}

	queue<int> q;
	x--; y--;
	q.push(x);
	visit[x] = true;
	int cnt = 0;
	while (!q.empty())
	{
		cnt++;
		int size = q.size();

		for (int i = 0; i < size; i++) {
			int now = q.front(); q.pop();

			for (auto j : num[now]) {
			
				if (!visit[j]) {
				
					if (j == y) {
						cout << cnt;
						return 0;
					}

					q.push(j);
					visit[j] = true;
				}
			}
		}
		
	}
	cout << -1;
}