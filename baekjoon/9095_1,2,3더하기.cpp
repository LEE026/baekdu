#include<iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int sum[100] = { 0,1,2,4 };
	int t;
	int n;
	int save=4;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		for (int j = save; j <= n; j++)
		{
			sum[j] = sum[j - 1] + sum[j - 2] + sum[j - 3];
		}
		if(save<n)
			save = n;
		cout << sum[n] << "\n";
	}

}
