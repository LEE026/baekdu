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

	int n;
	cin >> n;
	vector<pii> line(n);
	for (auto& i : line) {
		cin >> i.first >> i.second;
	}

	sort(line.begin(), line.end());

	vector<int> dp;

	for (auto i : line) {
		auto it = lower_bound(dp.begin(), dp.end(), i.second);
		if (it == dp.end()) {
			dp.push_back(i.second);
		}
		else {
			*it = i.second;
		}
	}

	cout << n - dp.size();
}