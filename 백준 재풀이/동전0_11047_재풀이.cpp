#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<int> coin(n);
	int cnt = 0;
	//vector<int> coin_cnt(n);

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		cnt += k / coin[i];
		k %= coin[i];
	}
	cout << cnt;
}