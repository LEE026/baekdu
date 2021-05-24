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

		//�ִ� 5200���̱⿡ �ð����� ū���������� ����
		vector<map<int, int>> graph(n + 1);//������ ������ +1

		for (int i = 0; i < m; i++) {
			cin >> s >> e >> t;

			//������ �ѹ��� �ΰ��� ���� �����Ƿ� �ϳ��� Ȯ���ص� �Ǵܰ���
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
		//��Ȧ�� ���°� ������ ª�⿡ �׳� �߰�
		//��Ȧ�� �ߺ��� �����̾߱Ⱑ ������
		for (int i = 0; i < w; i++) {
			cin >> s >> e >> t;
			graph[s][e] = -t;
		}
		//��������
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

		//�ִ� 5200���̱⿡ �ð����� ū���������� ����
		vector<vector<pair<int, int>>> graph(n + 1);//������ ������ +1

		//
		for (int i = 0; i < m; i++) {
			cin >> s >> e >> t;

			//������ �ѹ��� �ΰ��� ���� �����Ƿ� �ϳ��� Ȯ���ص� �Ǵܰ���
			graph[s].push_back({ e,t });
			graph[e].push_back({ s,t });
		}
		//��Ȧ�� ���°� ������ ª�⿡ �׳� �߰�
		//��Ȧ�� �ߺ��� �����̾߱Ⱑ ������
		for (int i = 0; i < w; i++) {
			cin >> s >> e >> t;
			graph[s].push_back({ e,-t });
		}

		//��������
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