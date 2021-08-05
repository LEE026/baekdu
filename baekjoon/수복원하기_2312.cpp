#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define MAX 100000LL

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	vector<int> prime(1, 2);

	vector<bool> isprime(MAX+1, true);

	for (ll i = 4; i <= MAX; i += 2) {
		isprime[i] = false;
	}
	for (ll i = 3; i <= MAX; i += 2) {
		if (isprime[i]) {
			prime.push_back(i);
			for (ll j = i * i; j <= MAX; j += i) {
				isprime[j] = false;
			}
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		for (auto i : prime) {
			if (n%i == 0) {
				int cnt = 0;
				while (n && n%i == 0) {
					cnt++;
					n /= i;
				}
				cout << i << " " << cnt << "\n";
			}
		}
	}
}