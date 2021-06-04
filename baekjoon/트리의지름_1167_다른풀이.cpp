#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

typedef pair<int, int> pii;

pii maxlen(vector < vector<pii>>& tree, int start) {
	queue<pii> q;
	vector<bool> visit(tree.size());
	q.push({ start,0 });
	visit[start] = true;
	int maxd = 0;
	int resv = 0;

	while (!q.empty()) {
		int v = q.front().first;
		int d = q.front().second;
		q.pop();

		if (maxd < d) {
			maxd = d;
			resv = v;
		}

		for (auto i : tree[v]) {
			if (!visit[i.first]) {
				visit[i.first] = true;
				q.push({ i.first,i.second + d });
			}
		}

	}

	return { resv,maxd };
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int v;
	cin >> v;
	vector < vector<pii>> tree(v + 1);//구형을 쉽게하기 위해 +1
	int num, to, d;
	for (int i = 0; i < v; i++) {
		cin >> num;
		while (true)
		{
			cin >> to;
			if (to == -1)
				break;
			cin >> d;

			tree[num].push_back({ to,d });
		}
	}

	//트리이기에 사이클이 없고, 예제처럼 양방향으로 이어진다고 가정
	//트리는 일반적으로 무방향그래프
	//어디에서 시작해도 상관 없음
	//단방향일경우 1이 root가 될 수 없는 상황이 있기에 반례발생

	cout << maxlen(tree, maxlen(tree, 1).first).second;
}