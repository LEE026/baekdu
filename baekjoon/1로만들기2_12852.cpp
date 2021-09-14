#include<iostream>
#include<vector>
#include<algorithm>

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
	vector<int> cnt(n + 1);
	vector<int> prev(n + 1);

	for (int i = 2; i <= n; i++) {
		int pre = i - 1;

		if (i % 3 == 0 && cnt[i / 3] < cnt[pre]) {
			pre = i / 3;
		}
		if (i % 2 == 0 && cnt[i / 2] < cnt[pre]) {
			pre = i / 2;
		}

		cnt[i] = cnt[pre] + 1;
		prev[i] = pre;
	}

	cout << cnt[n] << "\n";
	int now = n;
	while (now) {
		cout << now << " ";
		now = prev[now];
	}
}