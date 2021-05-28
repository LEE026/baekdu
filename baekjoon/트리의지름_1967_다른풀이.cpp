#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<pair<int, int>> parent(n+1);

	int p, s, w;

	for (int i = 1; i <n; i++) {
		cin >> p >> s >> w;
		parent[s]={ p,w };
	}
	int maxv = 0;
	vector<int> cost(n + 1);
	for (int i = n; i > 0;i--) {
		p = parent[i].first;
		w = parent[i].second;

		maxv = max(cost[p] + cost[i] + w, maxv);
		cost[p] = max(cost[p], cost[i] + w);
	}

	cout << maxv;
}