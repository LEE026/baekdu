#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	queue<int> q;
	int n, k;
	
	cin >> n >> k;
	vector<int> time(200001, 987654321);
	time[n] = 0;
	q.push(n);
	while (!q.empty())
	{
		int now = q.front(); q.pop();
		int nowtime = time[now];

		if (k > now) {
			if (time[now + 1] > nowtime + 1) {
				time[now + 1] = nowtime + 1;
				q.push(now + 1);
			}
			if (time[now * 2] > nowtime + 1) {
				time[now * 2] = nowtime + 1;
				q.push(now * 2);
			}
		}
		if (now > 0 && time[now - 1] > nowtime + 1) {
			time[now - 1] = nowtime + 1;
			q.push(now - 1);
		}
	}
	cout << time[k];
}