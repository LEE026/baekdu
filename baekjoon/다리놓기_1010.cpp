#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int testcase;
	int n, m;
	long long result;
	cin >> testcase;
	for (int t = 0; t < testcase; t++) {
		cin >> n >> m;
		result = 1;
		n = min(n, m - n);
		for (int i = 0; i < n; i++) {
			result *= m;
			m--;
		}
		for (int i = n; i > 1; i--) {
			result /= i;
		}
		cout << result << "\n";
	}
}