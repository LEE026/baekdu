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

		//최대 5200개이기에 시간에는 큰영향을주지 않음
		vector<map<int, int>> graph(n + 1);//구현이 쉽도록 +1

		for (int i = 0; i < m; i++) {
			cin >> s >> e >> t;

			//어차피 한번에 두개의 길을 이으므로 하나만 확인해도 판단가능
			auto tmp = graph[s].find(e);
			if (tmp == graph[s].end()) {
				graph[s][e] = t;
				graph[e][s] = t;
			}
			else {
				graph[s][e] = min(t, tmp->second);
				graph[e][s] = min(t, tmp->second);
			}
		}
		//웜홀로 가는게 무조건 짧기에 그냥 추가
		//웜홀은 중복에 대한이야기가 없었음
		for (int i = 0; i < w; i++) {
			cin >> s >> e >> t;
			graph[s][e] = -t;
		}
		//벨만포드
		vector<int> len(n + 1, 987654321);
		len[1] = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (auto point : graph[j]) {
					if (len[j] + point.second < len[point.first]) {
						len[point.first] = len[j] + point.second;
					}
				}
			}
		}



		bool yes = false;
		for (int j = 1; j <= n; j++) {
			for (auto point : graph[j]) {
				if (len[j] + point.second < len[point.first]) {
					yes = true;
					break;
				}
			}
			if (yes) break;
		}

		if (yes) cout << "YES\n";
		else cout << "NO\n";

	}
}#include<iostream>
#include<vector>
#include<map>
#include<queue>
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

		//최대 5200개이기에 시간에는 큰영향을주지 않음
		vector<vector<pair<int, int>>> graph(n + 1);//구현이 쉽도록 +1

		//
		for (int i = 0; i < m; i++) {
			cin >> s >> e >> t;

			//어차피 한번에 두개의 길을 이으므로 하나만 확인해도 판단가능
			graph[s].push_back({ e,t });
			graph[e].push_back({ s,t });
		}
		//웜홀로 가는게 무조건 짧기에 그냥 추가
		//웜홀은 중복에 대한이야기가 없었음
		for (int i = 0; i < w; i++) {
			cin >> s >> e >> t;
			graph[s].push_back({ e,-t });
		}

		//벨만포드
		vector<int> len(n + 1, 987654321);
		len[1] = 0;
		queue<int> q;
		q.push(1);
		bool yes = false;


		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (auto point : graph[j]) {
					if (len[j] + point.second < len[point.first]) {
						len[point.first] = len[j] + point.second;
						q.push(point.first);
						if (i == n - 1) yes = true;
					}
				}
			}

		}

		if (yes) cout << "YES\n";
		else cout << "NO\n";

	}
}