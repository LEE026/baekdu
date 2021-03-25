#include<iostream>
#include<algorithm>
#include<vector>
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
	sort(arr.begin(), arr.end(),greater<int>());
	int maxV=0;
	for (int i = 1; i <= n;i++) {
		maxV = max(maxV, arr[i-1]*i);
	}

	cout << maxV;
	
}