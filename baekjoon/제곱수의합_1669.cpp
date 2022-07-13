#include<iostream>
#include<algorithm>
#include<vector>

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
	
	

	for (int i = 1; i <= n; i++) {
		cnt[i] = cnt[i - 1] + 1;
		for (int j = 2; j * j <= i; j++) {
			cnt[i] = min(cnt[i], cnt[i - (j*j)] + 1);
		}
	}

	cout << cnt[n];
}