#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

typedef pair<int, int> pii;
#define INF 987654321

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<pii>> graph(n + 1);
	vector<int> len(n + 1, INF);
	vector<int> back(n + 1, -1);

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

	//출발점과 도착점은 무조건 이어져 있으므로 도착점이 나오기전에 pq가 비어있을 일은 없음
	while (pq.top().second != end) {
		int now = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		//top의 값이 이미 들어가 있는 값보다 크다는 것은
		//이미 최소 비용이 구해 졌다는 뜻이다
		if (len[now] < cost) continue;

		for (pii v : graph[now]) {
			int tmp = v.second + len[now];
			if (len[v.first] > tmp) {
				len[v.first] = tmp;
				back[v.first] = now;
				pq.push({ tmp,v.first });
			}
		}
	}
	//역추적
	vector<int> result;
	int tmp = end;
	while (tmp != -1) {
		result.push_back(tmp);
		tmp = back[tmp];
	}
	//결과 출력
	cout << len[end] << "\n";
	cout << result.size() << "\n";
	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i] << " ";
	}
}