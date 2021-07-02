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
	vector<int> len(n + 1,-1);

	int v1, v2, w;
	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2 >> w;
		graph[v1].push_back({ v2,w });
	}
	int start, end;
	cin >> start >> end;
	priority_queue<pii,vector<pii>,greater<pii>> pq;//{길이, 인덱스}
	pq.push({ 0,start });

	//출발점과 도착점은 무조건 이어져 있으므로 도착점이 나오기전에 pq가 비어있을 일은 없음
	while (true){
		//이미 최소거리가 결정된곳은 추가방문할 필요가없음
		while (len[pq.top().second]!=-1) {
			pq.pop();
		}

		int now = pq.top().second;

		//결과 출력 및 종료
		if (now == end) {
			cout << pq.top().first;
			return 0;
		}

		len[now] = pq.top().first;//현재 위치의 최단거리
		pq.pop();

		for (pii v : graph[now]) {
			pq.push({ v.second + len[now],v.first });
		}
	}


}