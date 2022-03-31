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
	vector<vector<int>> graph(n);
	vector<int> inDegree(n);

	for (int i = 0; i < m; i++) {
		int num, prev = -1, v;
		cin >> num;
		while (num--) {
			cin >> v;
			v--;
			if (prev >= 0) {
				graph[prev].push_back(v);
				inDegree[v]++;
			}
			prev = v;
		}
	}

	vector<int> result;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (inDegree[i]==0) {
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int now = q.front(); q.pop();
		result.push_back(now);
		for (auto v : graph[now]) {
			inDegree[v]--;
			if (inDegree[v] == 0) {
				q.push(v);
			}
		}
	}

	if (result.size() != n) {
		cout << "0\n";
	}
	else {
		for (auto i : result) {
			cout << i+1 << "\n";
		}
	}



}