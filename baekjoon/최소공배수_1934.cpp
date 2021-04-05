#include<iostream>
using namespace std;

int gcd(int a, int b) {
	if (a%b == 0)
		return b;
	else
		return gcd(b, a%b);
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int testcase;
	int a, b;
	cin >> testcase;
	for (int t = 0; t < testcase; t++) {
		cin >> a >> b;
		
		cout << a * b / gcd((a>b)?a:b, (b > a) ? a : b) << "\n";
	}
}