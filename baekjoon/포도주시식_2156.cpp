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
	vector<vector<int>> dp(2, vector<int>(3));

	int amount;
	for (int i = 1; i <= n; i++) {
		cin >> amount;
		vector<int>& prev = dp[(i + 1) % 2];
		vector<int>& now = dp[i%2];

		now[0] = max(prev[0], max(prev[1], prev[2]));
		now[1] = prev[0] + amount;
		now[2] = prev[1] + amount;
	}

	vector<int>& last = dp[n % 2];
	cout << max(last[0], max(last[1], last[2]));
}