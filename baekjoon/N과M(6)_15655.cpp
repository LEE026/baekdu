#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void makeSequence(vector<int>& arr, vector<int>& in, int m, int i) {
	if (in.size() == m) {
		for (auto num : in){
			cout << num << " ";
		}
		cout << "\n";
	}
	else if (arr.size() - i >= m - in.size()){
		in.push_back(arr[i]);
		makeSequence(arr, in, m, i + 1);
		in.pop_back();
		makeSequence(arr, in, m, i + 1);
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	vector<int> in;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	makeSequence(arr, in, m, 0);
}