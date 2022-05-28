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

	int m, n;
	cin >> m >> n;

	int sum = 0;
	int minv = 987654321;
	for (int i = max(m,2); i <= n; i++) {
		if(i!=2 && i%2==0) continue;
		bool isPrime = true;
		for (int j = 3; j*j <= i; j += 2) {
			if (i%j == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			minv = min(minv, i);
			sum += i;
		}
	}

	if (sum == 0) cout << -1 << "\n";
	else cout << sum << "\n" << minv << "\n";
}