#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define MAX 5000000LL

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	vector<int> minPrime(MAX+1,-1);

	for (ll i = 4; i <= MAX; i += 2) {
		minPrime[i] = 2;
	}

	for (ll i = 3; i*i <= MAX; i += 2) {
		if (minPrime[i]==-1) {
			for (ll j = i*i; j <= MAX; j += i) {				
				//if (minPrime[j] == -1)
					minPrime[j] = i;
			}
		}
	}

	int n,k;
	cin >> n;
	while (n--) {
		cin >> k;
		
		while (minPrime[k] != -1) {
			cout << minPrime[k] << " ";
			k /= minPrime[k];
		}
		if (k >= 2) cout << k;

		cout << "\n";
	}
}