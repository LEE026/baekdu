#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void seleteNum(vector<int>& arr,vector<int>& res,int i) {
	if (res.size() == 6) {
		for (auto i : res) {
			cout << i << " ";
		}
		cout << "\n";
	}
	else if(i<arr.size()){
		res.push_back(arr[i]);
		seleteNum(arr, res, i + 1);
		res.pop_back();
		seleteNum(arr, res, i + 1);
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int k;
	while (true)
	{
		cin >> k;
		if (k == 0) break;
		vector<int> arr(k);
		for (auto& i : arr) {
			cin >> i;
		}

		sort(arr.begin(), arr.end());

		vector<int> res;
		seleteNum(arr, res, 0);
		cout << "\n";
	}
}