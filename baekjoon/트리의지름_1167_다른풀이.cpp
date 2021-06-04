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
	vector < vector<pii>> tree(v + 1);//������ �����ϱ� ���� +1
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

	//Ʈ���̱⿡ ����Ŭ�� ����, ����ó�� ��������� �̾����ٰ� ����
	//Ʈ���� �Ϲ������� ������׷���
	//��𿡼� �����ص� ��� ����
	//�ܹ����ϰ�� 1�� root�� �� �� ���� ��Ȳ�� �ֱ⿡ �ݷʹ߻�

	cout << maxlen(tree, maxlen(tree, 1).first).second;
}