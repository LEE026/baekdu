#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	if (k <= n) {
		cout << n - k << "\n" << 1;
		return 0;
	}

	vector<bool> visit(k + 2, false);
	visit[n] = true;
	queue<pair<int, int>> q;
	q.push({ n,0 });
	int cnt = 0;

	int minv = 987654321;
	while (!q.empty()) {
		int now = q.front().first;
		int time = q.front().second;
		q.pop();


		if (time > minv) continue;

		visit[now] = true;

		if (now == k) {
			minv = time;
			cnt++;
			continue;
		}

		//bfs는 각단계별로 확인하기에 다음 번은 지금보다 길 수 밖에 없음
		if (now > 0 && !visit[now - 1]) {
			q.push({ now - 1 , time + 1 });
		}
		if (now < k && !visit[now + 1]) {
			q.push({ now + 1 , time + 1 });
		}
		if (now <= (k + 1) / 2 && !visit[now * 2]) {
			q.push({ now * 2 , time + 1 });
		}
	}
	cout << minv << "\n" << cnt;

}