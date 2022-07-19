#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr(n);

	for (auto& i : arr) {
		cin >> i;
	}
	sort(arr.begin(), arr.end());

	int l = 0, r = n - 1;
	int resl = -1, resr = -1;
	int res = INT_MAX;
	
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(arr.begin() + i + 1, arr.end(), -arr[i]) - arr.begin();
		
		if (idx != n && abs(arr[idx] + arr[i]) < res) {
			resl = arr[i];
			resr = arr[idx];
			res = abs(arr[idx] + arr[i]);
		}
		if (idx-1!=i) {
			idx--;
			if (abs(arr[idx] + arr[i]) < res) {
				resl = arr[i];
				resr = arr[idx];
				res = abs(arr[idx] + arr[i]);
			}
		}
	}
	cout << resl << " " << resr;
}