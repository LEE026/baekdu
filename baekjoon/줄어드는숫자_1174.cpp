#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> num(10, 100);
	num[9] = 0;
	for (int i = 1; i < n; i++) {
		if (num[0] == 9) {
			cout << -1;
			return 0;
		}
		num[9]++;
		for (int i = 9; i > 0; i--) {
			if (num[i] == 100) break;
			if (num[i] > 9 || num[i - 1] <= num[i]) {
				num[i] = 9 - i;
				num[i - 1]++;
				if (num[i - 1] == 101) {
					num[i - 1] = 9 - (i - 1);
					break;
				}
			}

		}
	}
	for (auto i : num) {
		if (i < 10) {
			cout << i;
		}
	}
}