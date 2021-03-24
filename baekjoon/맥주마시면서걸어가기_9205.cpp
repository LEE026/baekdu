#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	
	int testcase;
	int n;
	int d;
	cin >> testcase;
	for (int t = 0; t < testcase; t++) {
		cin >> n;
		vector < pair<int, int>> v(n+2);
		vector <int> dist(n+2,987654321);
		for (int i = 0; i < n+2; i++) {
			cin >> v[i].first>>v[i].second;
		}
		dist[0] = 0;
		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			int now = q.front(); q.pop();
			for (int i = 1; i < n + 2; i++) {
				if (now == i) continue;//������ �� x

				d = abs(v[now].first - v[i].first) + abs(v[now].second - v[i].second);
				if (d <= 1000 && dist[i] > 1000) {
					//1000���� ũ�� �ٲٴ� �ǹ̰� ���� ���簪�� 1000���϶�� �ǹ̾���
					dist[i] = d;
					q.push(i);
				}
			}
		}

		cout << ((dist[n + 1] <= 1000) ? "happy\n" : "sad\n");
	}
}