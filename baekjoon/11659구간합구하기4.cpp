#include<iostream>
#include<algorithm>
using namespace std;

int num[100001] = { 0 };
int sum[100001] = { 0 };

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
		num[i] += num[i - 1];
	}
	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		cout << num[b] - num[a - 1] << "\n";
	}
}