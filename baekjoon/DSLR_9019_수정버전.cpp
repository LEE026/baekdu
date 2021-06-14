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
		vector<char> arr(MAX, '.');
		vector<int> prev(MAX);
		queue<int> q;
		q.push(a);
		arr[a] = '-';
		arr[a] = -1;
		while (!q.empty()) {
			int now = q.front(); q.pop();
			if (now == b) {
				string s = "";
				while (now != a) {
					s += arr[now];
					now = prev[now];
				}
				reverse(s.begin(), s.end());
				cout << s << "\n";
				break;
			}
			int tmp = now * 2 % MAX;
			if (arr[tmp] == '.') {
				arr[tmp] = 'D';
				prev[tmp] = now;
				q.push(tmp);
			}
			tmp = (now + MAX - 1) % MAX;
			if (arr[tmp] == '.') {
				arr[tmp] = 'S';
				prev[tmp] = now;
				q.push(tmp);
			}
			tmp = now % 1000 * 10 + now / 1000;
			if (arr[tmp] == '.') {
				arr[tmp] = 'L';
				prev[tmp] = now;
				q.push(tmp);
			}
			tmp = now % 10 * 1000 + now / 10;
			if (arr[tmp] == '.') {
				arr[tmp] = 'R';
				prev[tmp] = now;
				q.push(tmp);
			}
		}

	}
}