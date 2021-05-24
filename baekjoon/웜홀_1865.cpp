#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	int n, m, w;
	int s, e, t;
	for (int tt = 0; tt < tc; tt++) {
		cin >> n >> m >> w;

		vector<vector<pair<int, int>>> graph(n + 1);//구현이 쉽도록 +1

		for (int i = 0; i < m; i++) {
			cin >> s >> e >> t;

			graph[s].push_back({ e,t });
			graph[e].push_back({ s,t });
		}
		for (int i = 0; i < w; i++) {
			cin >> s >> e >> t;
			graph[s].push_back({ e,-t });
		}

		//벨만포드
		vector<int> len(n + 1, 987654321);
		len[1] = 0;
		bool yes = false;


		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (auto point : graph[j]) {
					if (len[j] + point.second < len[point.first]) {
						len[point.first] = len[j] + point.second;
						if (i == n - 1) yes = true;
					}
				}
			}

		}

		if (yes) cout << "YES\n";
		else cout << "NO\n";

	}
}