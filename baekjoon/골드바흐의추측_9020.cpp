#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define MAX 10000

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);


	vector<bool> isprime(MAX + 1, true);

	for (int i = 4; i <= MAX; i += 2) {
		isprime[i] = false;
	}

	for (int i = 3; i*i <= MAX; i += 2) {
		if (isprime[i]) {
			for (int j = i * i; j <= MAX; j += i) {
				isprime[j] = false;
			}
		}
	}

	vector<int> prime;
	prime.push_back(2);
	for (int i = 3; i <= MAX; i += 2) {
		if (isprime[i]) {
			prime.push_back(i);
		}
	}


	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;

		int l = 0;
		int r = lower_bound(prime.begin(), prime.end(), n) - prime.begin() - 1;

		pii res;
		while (l <= r)
		{
			int now = prime[l] + prime[r];
			if (now == n) {
				res = { prime[l],prime[r] };
				l++;
				r--;
			}
			else if (now > n)
			{
				r--;
			}
			else
			{
				l++;
			}
		}
		cout << res.first << " " << res.second << "\n";
	}
}