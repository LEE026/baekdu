#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> arr(n);

	for(auto& i: arr) {
		cin >> i;
	}
	sort(arr.begin(), arr.end());


	int minv = INT32_MAX;
	pii idx;
	for (int i = 1; i < n; i++) {
		int now = arr[i-1];//ÇöÀç °ª
		int pos = lower_bound(arr.begin() + i, arr.end(), -now)-arr.begin();

		if (pos<n && abs(arr[pos]+now) < minv) {
			minv = abs(arr[pos] + now);
			idx = { now,arr[pos] };
		}

		pos--;
		if (pos>=i && abs(arr[pos] + now) < minv) {;
			minv = abs(arr[pos] + now);
			idx = { now,arr[pos] };
		}

	}

	cout << idx.first << " " << idx.second;

}