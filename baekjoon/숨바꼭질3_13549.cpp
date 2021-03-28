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
		cout << n - k;
		return 0;
	}
	vector<int> cnt(k * 2 + 1, 987654321);//k+1까지만 있어도 됨
	queue<int> q;
	q.push(n);
	cnt[n] = 0;

	while (!q.empty())
	{
		int now = q.front(); q.pop();

		if (n/2 < now - 1 && cnt[now] + 1 < cnt[now - 1]) {
			cnt[now - 1] = cnt[now] + 1;
			q.push(now - 1);
		}
		if (now + 1 <= k && cnt[now] + 1 < cnt[now + 1]) {
			cnt[now + 1] = cnt[now] + 1;
			q.push(now + 1);
		}
		if (now * 2 < k * 2 && cnt[now] < cnt[now * 2]) {
			cnt[now * 2] = cnt[now];
			q.push(now * 2);
		}
	}

	cout << cnt[k];
}