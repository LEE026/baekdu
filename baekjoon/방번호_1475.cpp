#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	vector<int> cnt(10, 0);
	cin >> n;
	if (n == 0) {
		cout << 1;
		return 0;
	}
	
	while (n != 0) {
		cnt[n % 10]++;
		n /= 10;
	}
	int maxv = 0;
	cnt[6] = (cnt[6] + cnt[9]) / 2 + (cnt[6] + cnt[9]) % 2;
	cnt.pop_back();
	for (auto i : cnt) {
		maxv = max(maxv, i);
	}
	cout << maxv;
}