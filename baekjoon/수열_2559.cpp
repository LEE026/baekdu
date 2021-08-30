#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	int sum = 0;
	vector<int> arr(n);
	for (auto& i : arr) {
		cin >> i;
	}
	int i;
	for (i = 0; i < k; i++) {
		sum += arr[i];
	}

	int maxv = sum;
	for (; i < n; i++) {
		sum += arr[i] - arr[i - k];
		maxv = max(maxv, sum);
	}

	cout << maxv;

}