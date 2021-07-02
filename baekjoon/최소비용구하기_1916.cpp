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
	priority_queue<pii,vector<pii>,greater<pii>> pq;//{����, �ε���}
	pq.push({ 0,start });

	//������� �������� ������ �̾��� �����Ƿ� �������� ���������� pq�� ������� ���� ����
	while (true){
		//�̹� �ּҰŸ��� �����Ȱ��� �߰��湮�� �ʿ䰡����
		while (len[pq.top().second]!=-1) {
			pq.pop();
		}

		int now = pq.top().second;

		//��� ��� �� ����
		if (now == end) {
			cout << pq.top().first;
			return 0;
		}

		len[now] = pq.top().first;//���� ��ġ�� �ִܰŸ�
		pq.pop();

		for (pii v : graph[now]) {
			pq.push({ v.second + len[now],v.first });
		}
	}


}