#include<iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	bool win[5] = { 0,1,0,1,1 };
	long long n;

	cin >> n;

	if (win[n % 5L])
		cout << "SK";
	else
		cout << "CY";

	/*for (int i = 1; i <= n; i++) {
		cout << win[i % 5L] << " ";
		if (i % 5 == 0) {
			cout << "\n";
		}
	}*/



}