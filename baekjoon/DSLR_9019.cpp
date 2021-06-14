#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

#define MAX 10000

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	int a, b;
	for (int t = 0; t < tc; t++) {
		cin >> a >> b;
		vector<string> arr(MAX, "");
		queue<int> q;
		q.push(a);
		arr[a] = "-";
		while (!q.empty()) {
			int now = q.front(); q.pop();
			if (now == b) {
				cout << arr[now].substr(1, arr[now].size() - 1) << "\n";
				break;
			}
			int tmp = now * 2 % MAX;
			if (arr[tmp] == "") {
				arr[tmp] = arr[now] + "D";
				q.push(tmp);
			}
			tmp = (now + MAX - 1) % MAX;
			if (arr[tmp] == "") {
				arr[tmp] = arr[now] + "S";
				q.push(tmp);
			}
			tmp = now % 1000 * 10 + now / 1000;
			if (arr[tmp] == "") {
				arr[tmp] = arr[now] + "L";
				q.push(tmp);
			}
			tmp = now % 10 * 1000 + now / 10;
			if (arr[tmp] == "") {
				arr[tmp] = arr[now] + "R";
				q.push(tmp);
			}
		}

	}
}