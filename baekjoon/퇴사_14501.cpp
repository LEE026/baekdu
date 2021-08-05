#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void countMoney(vector<pii>& arr, int& maxv, int money, int day) {
	if (day > arr.size()) return;

	if (day == arr.size()) {
		maxv = max(maxv, money);
	}
	else {
		countMoney(arr, maxv, money + arr[day].second, day + arr[day].first);
		countMoney(arr, maxv, money, day+1);
	}

}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<pii> arr(n);

	for (auto& i : arr) {
		cin >> i.first >> i.second;
	}

	int maxv = 0;
	countMoney(arr, maxv, 0, 0);

	cout << maxv;
}