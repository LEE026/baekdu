#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int dfs(vector<vector<int>>& graph, vector<int>& visit,
	vector<pii>& result,int& num,int now,int prev) {
	int discover = visit[now];
	for (auto v : graph[now]) {
		if (v == prev) continue;
		if (!visit[v]) {
			visit[v] = num++;

			int subDiscover = dfs(graph, visit, result, num, v,now);
			if (visit[now] < subDiscover) {
				result.push_back({ min(now,v),max(now,v) });
			}
			discover = min(discover, subDiscover);
		}
		else
		{
			discover = min(discover, visit[v]);
		}
	}
	return discover;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int v, e;
	cin >> v >> e;
	vector<vector<int>> graph(v+1);
	vector<int> visit(v + 1);
	vector<pii> result;
	int num = 1;
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(graph, visit, result, num, 1,-1);

	sort(result.begin(), result.end());

	cout << result.size() << "\n";
	for (auto i : result) {
		cout << i.first << " " << i.second << "\n";
	}


}