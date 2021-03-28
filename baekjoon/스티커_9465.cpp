#include<iostream>
#include<algorithm>
using namespace std;

int list[100000][2];

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	
	int testcase;
	int n;
	cin >> testcase;

	for (int t = 0; t < testcase; t++) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> list[j][i];
			}
		}
		if (n == 1) {
			cout << max(list[0][0], list[0][1]);
			continue;
		}
		list[1][0] += list[0][1];
		list[1][1] += list[0][0];

		for (int i = 2; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				list[i][j] = max(max(list[i - 2][0], list[i - 2][1]), list[i - 1][(j + 1) % 2]) + list[i][j];
			}
		}
		cout << max(list[n - 1][0], list[n - 1][1])<<"\n";
	}

}