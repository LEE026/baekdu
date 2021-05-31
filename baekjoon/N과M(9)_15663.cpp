#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

void print(vector<int>& arr, vector<bool>& in, string result, int n, int m, int len) {
	if (m == len) {
		cout << result << "\n";
	}

	int prev = -1;
	for (int i = 0; i < n; i++) {
		if (!in[i] && arr[i] != prev) {
			in[i] = true;
			print(arr, in, result + to_string(arr[i]) + " ", n, m, len + 1);
			in[i] = false;
			prev = arr[i];
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	vector<bool> in(n);
	print(arr, in, "", n, m, 0);
}