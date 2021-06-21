#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

int len(vector<bool>& broken, int num) {
	if (num < 0 || num>1000000) return 0;
	if (num == 0)
		return !broken[0];

	int cnt = 0;
	while (num)
	{
		cnt++;
		if (broken[num % 10])
			return 0;
		num /= 10;
	}
	return cnt;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<bool> broken(10);
	int input;
	for (int i = 0; i < m; i++) {
		cin >> input;
		broken[input] = true;
	}

	int minv = abs(n - 100);
	int last = max(n, 500000);
	for (int i = 0; i <= last; i++) {
		int numlen = len(broken, n-i);
		if (numlen) {
			minv = min(minv, i + numlen);
			break;
		}
		numlen = len(broken, n+i);
		if (numlen) {
			minv = min(minv, i + numlen);
			break;
		}
	}
	cout << minv;
}