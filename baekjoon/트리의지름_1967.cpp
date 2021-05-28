#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxlen(vector<vector<pair<int, int>>>& graph, int& maxv, int v) {
	int one=0, two=0;
	for (auto i : graph[v]) {
		int tmp = maxlen(graph, maxv, i.first)+i.second;
		if (one < tmp) {
			two = one;
			one = tmp;
		}
		else if (two < tmp) {
			two = tmp;
		}
	}
	maxv = max(maxv, one + two);
	//cout << v << " ";
	return one;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<pair<int,int>>> graph(n+1);

	int p, s, w;

	for (int i = 1; i < n; i++) {
		cin >> p >> s >> w;
		graph[p].push_back({ s,w });
	}
	int maxv = 0;
	maxlen(graph, maxv, 1);

	cout << maxv;
}