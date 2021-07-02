#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

typedef pair<int, int> pii;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<pii>> graph(n + 1);
	vector<int> len(n + 1, 987654321);

	int v1, v2, w;
	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2 >> w;
		graph[v1].push_back({ v2,w });
	}
	int start, end;
	cin >> start >> end;
	priority_queue<pii, vector<pii>, greater<pii>> pq;//{길이, 인덱스}
	pq.push({ 0,start });
	len[start] = 0;
	while (!pq.empty()) {
		
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		//들어간후 더 짧은게 나왔을 경우 이전에 들어갔던걸 걸러주기 위한 것
		if (len[now] < cost) continue;

		for (pii v : graph[now]) {
			int tmp = v.second + len[now];
			if (len[v.first] > tmp) {
				len[v.first] = tmp;
				pq.push({ tmp,v.first });
			}
		}
	}
	cout << len[end];

}