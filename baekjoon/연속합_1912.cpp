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
	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	int minv = 0;
	int maxv = -987654321;

	for (int i = 1; i <= n; i++) {
		maxv = max(maxv, arr[i] - minv);
		minv = min(minv, arr[i]);
	}

	cout << maxv;
}