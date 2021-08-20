#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int dfs(vector<vector<int>>& order, vector<int>& time,vector<int>& result, int now) {
	if (result[now] == -1) {
		for (auto v : order[now]) {
			int prev = dfs(order, time, result, v);
			result[now] = max(result[now], prev + time[v]);
		}
	}
	result[now] = max(result[now], 0);
	return result[now];
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {

		int n, k, w;
		cin >> n >> k;
		vector<int> time(n + 1);
		vector<vector<int>> order(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> time[i];
		}

		int a, b;
		for (int i = 0; i < k; i++) {
			cin >> a >> b;
			order[b].push_back(a);
		}



		cin >> w;

		vector<int> result(n + 1,-1);

		int res = dfs(order, time, result, w) + time[w];
		cout << res << "\n";
	}
}