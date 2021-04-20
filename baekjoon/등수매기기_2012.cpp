#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	long long result = 0;
	for (int i = 1; i <= n; i++) {
		result += abs(arr[i - 1] - i);
	}

	cout << result;
}