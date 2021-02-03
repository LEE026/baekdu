#include<iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int t;
	int h, w, n;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> h >> w >> n;
		cout << ((n-1)%h+1) * 100 + (n-1) / h + 1 << "\n";
	}
}