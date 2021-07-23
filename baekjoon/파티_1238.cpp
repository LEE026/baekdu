#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void shortdist(vector<vector<pii>>& graph, vector<int>& dist, int start) {
	priority_queue<pii> pq;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int d = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (dist[now] < d) continue;

		for (auto v : graph[now]) {
			int len = d + v.second;
			if (len < dist[v.first]) {
				dist[v.first] = len;
				pq.push({ -len,v.first });
			}

		}
	}

}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m, x;
	cin >> n >> m >> x;
	vector<vector<pii>> graph(n + 1);

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}

	vector<vector<int>> dist(n + 1, vector<int>(n + 1, 987654321));

	for (int i = 1; i <= n; i++) {
		shortdist(graph, dist[i], i);
	}

	int result = 0;
	for (int i = 1; i <= n; i++) {
		if (i == x) continue;
		result = max(result, dist[i][x] + dist[x][i]);
	}

	cout << result;
}