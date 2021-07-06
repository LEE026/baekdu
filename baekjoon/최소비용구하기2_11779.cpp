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

	priority_queue<pii, vector<pii>, greater<pii>> pq;//{����, �ε���}
	pq.push({ 0,start });
	len[start] = 0;

	//������� �������� ������ �̾��� �����Ƿ� �������� ���������� pq�� ������� ���� ����
	while (pq.top().second != end) {
		int now = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		//top�� ���� �̹� �� �ִ� ������ ũ�ٴ� ����
		//�̹� �ּ� ����� ���� ���ٴ� ���̴�
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
	//������
	vector<int> result;
	int tmp = end;
	while (tmp != -1) {
		result.push_back(tmp);
		tmp = back[tmp];
	}
	//��� ���
	cout << len[end] << "\n";
	cout << result.size() << "\n";
	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i] << " ";
	}
}