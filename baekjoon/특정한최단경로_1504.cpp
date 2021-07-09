#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>

#define INF 987654321
using namespace std;

typedef pair<int, int> pii;

void dijkstra(vector<vector<pii>>& graph, vector<int>& cost, int start) {
	priority_queue<pii> pq;//{비용,정점}
	cost[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty())
	{
		int nowcost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (cost[now] < nowcost) continue;

		for (auto v : graph[now]) {//그래프는 first가 정점
			int tmp = nowcost + v.second;
			if (tmp < cost[v.first]) {
				cost[v.first] = tmp;
				pq.push({ -tmp,v.first });
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, e;
	cin >> n >> e;

	//무방향 그래프 제작
	vector<vector<pii>> graph(n + 1);
	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	int v1, v2;
	cin >> v1 >> v2;
	vector<int> startcost(n + 1, INF);
	vector<int> cost1(n + 1, INF);
	vector<int> cost2(n + 1, INF);
	dijkstra(graph, startcost, 1);
	dijkstra(graph, cost1, v1);
	dijkstra(graph, cost2, v2);

	if (startcost[n] == INF)
		cout << -1;
	else
		cout << min(startcost[v1] + cost1[v2] + cost2[n], startcost[v2] + cost2[v1] + cost1[n]);
}