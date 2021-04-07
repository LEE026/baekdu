#include<iostream>
#include<vector>
using namespace std;

#define MOD 1000000000

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	int sign = n;
	n = (n < 0) ? -n : n;

	vector<int> fibo(n + 2);
	fibo[0] = 0;
	fibo[1] = 1;
	if (sign < 0) {
		for (int i = 2; i <= n; i++) {
			fibo[i] = (fibo[i - 2] - fibo[i - 1])%MOD;
		}
	}
	else
	{
		for (int i = 2; i <= n; i++) {
			fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;
		}
	}


	if (fibo[n] < 0) {
		cout << -1;
	}
	else if (fibo[n] > 0) {
		cout << 1;
	}
	else {
		cout << 0;
	}
	cout << "\n";
	cout << ((fibo[n] < 0) ? -fibo[n] : fibo[n]);
}