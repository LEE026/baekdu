#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> arr(2, vector<int>(n + 1));

		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
			}
		}

		int result = max(arr[0][1], arr[1][1]);
		for (int j = 2; j <= n; j++) {
			for (int i = 0; i < 2; i++) {
				arr[i][j] += max(arr[(i + 1) % 2][j - 1], arr[(i + 1) % 2][j - 2]);
				result = max(result, arr[i][j]);
			}
		}
		cout << result << "\n";
	}

}