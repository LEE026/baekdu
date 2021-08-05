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


	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int i = 2;
		if (n%i == 0) {
			int cnt = 0;
			while (n && n%i == 0) {
				cnt++;
				n /= i;
			}
			cout << i << " " << cnt << "\n";
		}

		for (i = 3; i <= n; i += 2) {
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