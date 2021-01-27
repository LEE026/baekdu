#include<iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int a, b;
	while (true)
	{
		cin >> a >> b;
		if (cin.eof())
			break;
		cout << a + b << "\n";
	}
}