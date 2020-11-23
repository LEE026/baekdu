#include<iostream>
using namespace std;

bool win[1001] = { 1,0,1,0 };

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 4; i <= n; i++)
	{
		win[i] = (!win[i - 1] || !win[i - 3] || !win[i - 4]);
	}

	if (win[n]) {
		cout << "SK";
	}

	else {
		cout << "CY";
	}

}
