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

	int n, k;
	cin >> n >> k;
	vector<int> coins(n);
	for (auto& coin : coins) {
		cin >> coin;
	}

	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		cnt += k / coins[i];
		k %= coins[i];
	}
	cout << cnt;
}