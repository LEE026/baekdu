#include<iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, k;
	int a, b;
	cin >> n >> k;
	a = b = 1;

	if (k == 0) cout << "1";
	else
	{
		for (int i = 1; i <= k; i++)
		{
			a *= n - i + 1;
			b *= i;
		}
		cout << a / b;
	}
}