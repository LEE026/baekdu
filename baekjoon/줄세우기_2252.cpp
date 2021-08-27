#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> order(n + 1);
	vector<int> indegree(n + 1);

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		order[a].push_back(b);
		indegree[b]++;
	}

	queue<int> q;
	

	for (int i = 1; i <= n; i++) {
		if (indegree[i]==0) {
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int now = q.front(); q.pop();
		cout << now << " ";
		for (auto v : order[now]) {
			indegree[v]--;
			if (indegree[v] == 0) {
				q.push(v);
			}
		}
	}



}