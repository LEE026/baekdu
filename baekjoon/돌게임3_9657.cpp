#include<iostream>
using namespace std;

bool win[1001] = { 0,1,0,1,1 };

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 5; i <= n; i++)
	{
		win[i] = (!win[i - 1] || !win[i - 3] || !win[i - 4]);
	}

	/*for (int i = 1; i <= n;i++) {
		cout << win[i] << " ";
		if (i % 7 == 0)
			cout << "\n";
	}
	cout << "\n";
*/
	if (win[n]) {
		cout << "SK";
	}

	else {
		cout << "CY";
	}

}
