#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

vector<int> visit;
int num = 1;
vector<int> result;

int dfs(vector<vector<int>>& graph, int now) {
	int nowNum = visit[now];
	int low = num;
	int cnt = 0;
	bool isCutV = false;

	for (auto v : graph[now]) {
		if (!visit[v]) {
			visit[v] = num++;
			cnt++;
			int sublow = dfs(graph, v);
			if (nowNum <= sublow) {
				isCutV = true;
			}
			low = min(low, sublow);
		}
		else if (visit[now] - 1 != visit[v])
		{
			low = min(low, visit[v]);
		}
	}
	if (nowNum == 1) {
		if(cnt >= 2)
			result.push_back(now);
	}
	else if (isCutV) {
		result.push_back(now);
	}
	return low;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int v, e;
	cin >> v >> e;
	visit.assign(v + 1,0);
	vector<vector<int>> graph(v + 1);

	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= v; i++) {
		if (!visit[i]) {
			num = 1;
			visit[i] = num++;
			dfs(graph, i);
		}
	}
	
	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (auto i:result) {
		cout << i << " ";
	}
}