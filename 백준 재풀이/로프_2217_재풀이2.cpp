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
	vector<int> ropes(n);
	for (auto& rope : ropes) {
		cin >> rope;
	}
	sort(ropes.rbegin(), ropes.rend());
	int maxv = 0;
	for (int i = 0; i < n; i++) {
		maxv = max(maxv, ropes[i] * (i + 1));
	}
	cout << maxv;

}