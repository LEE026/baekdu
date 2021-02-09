#include<iostream>
using namespace std;

int gcd(int a, int b);

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	int num = gcd(a, b);

	cout << num << "\n";
	cout << (a*b) / num;
}

int gcd(int a, int b) {
	int temp;
	while (b>0)
	{
		temp = a;
		a = b;
		b = temp % b;
	}
	return a;
}
