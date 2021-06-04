#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxlen(vector < vector<pair<int, int>>>& tree,vector<bool>& visit,int& maxv, int num) {
	int one = 0;
	int two = 0;

	visit[num] = true;

	int len;
	//자식중 가장 긴 두개 고르기
	for (auto v : tree[num]) {
		if (!visit[v.first]) {
			len = maxlen(tree, visit, maxv, v.first) + v.second;
			if (one < len) {
				two = one;
				one = len;
			}
			else if (two < len) {
				two = len;
			}
		}
	}

	maxv = max(one + two, maxv);
	return one;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int v;
	cin >> v;
	vector < vector<pair<int, int>>> tree(v + 1);//구형을 쉽게하기 위해 +1
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
	vector<bool> visit(v + 1);
	int maxv = 0;
	maxlen(tree, visit, maxv, 1);
	cout << maxv;
}