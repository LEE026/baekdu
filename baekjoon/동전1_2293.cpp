#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	int coin;
	vector<int> cnt(k+1);

	cnt[0] = 1;//아무것도 안주는 1가지 방법이 있음

	for (int i = 0; i < n; i++){
		cin >> coin;
		for (int i = coin; i <= k; i++) {
			cnt[i] += cnt[i - coin];
		}
	}

	cout << cnt[k];

}