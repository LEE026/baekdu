#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, k;
	vector<int> arr(1000001);
	cin >> n >> k;
	int g, x;
	for (int i = 0; i < n; i++) {
		cin >> g >> x;
		arr[x] = g;
	}
	long long sum = 0;
	for (int i = 0; i<arr.size() && i <= 2*k; i++) {
		sum += arr[i];
	}

	long long maxv = sum;
	int i = 0, j = 2 * k;

	while (j < 1000000) {
		sum -= arr[i++];
		sum += arr[++j];
		maxv = max(maxv, sum);
	}

	cout << maxv;

	return 0;

}