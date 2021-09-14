#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	map<int, int> prev;
	queue<int> q;
	q.push(n);
	prev[n] = 0;

	while (!q.empty()) {

		int now = q.front(); q.pop();

		if (now == 1) {
			break;
		}

		if (now % 3 == 0 && prev[now / 3] == 0) {
			prev[now / 3] = now;
			q.push(now / 3);
		}
		if (now % 2 == 0 && prev[now / 2] == 0) {
			prev[now / 2] = now;
			q.push(now / 2);
		}
		if (prev[now - 1] == 0) {
			prev[now - 1] = now;
			q.push(now - 1);
		}
	}

	int now = 1;
	vector<int> res;
	while (now) {//n¿∫ prev∞° 0¿”
		res.push_back(now);
		now = prev[now];
	}
	cout << res.size() - 1 << "\n";
	for (int i = res.size() - 1; i >= 0; i--) {
		cout << res[i] << " ";
	}

}