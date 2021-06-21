#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

int len(vector<bool>& broken,int num) {
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
	for (int i = 0; i <= 1000000; i++) {
		int numlen = len(broken, i);
		if (numlen) {
			minv = min(minv, abs(n - i) + numlen);
		}
	}
	cout << minv;
}