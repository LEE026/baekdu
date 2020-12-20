#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	int num;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		if (i % 2 != num % 2) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

}