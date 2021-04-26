#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	int tmp;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		auto it = lower_bound(arr.begin(), arr.end(), tmp);
		if (it!=arr.end() && *it==tmp) {
			cout <<"1 ";
		}
		else {
			cout << "0 ";
		}
	}
}