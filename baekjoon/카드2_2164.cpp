#include<iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int n;
	int pow;

	cin >> n;
	if (n <= 2)
		cout << n;
	else {
		pow = 4;
		while (n>pow)
		{
			pow *= 2;
		}
		cout << pow - 2 * (pow - n);
	}
}