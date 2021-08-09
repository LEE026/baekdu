#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<pii> arr(n);
	map<int,int> c;
	for (auto& i : arr) {
		cin >> i.second >> i.first;//{가치,무게}가 되도록
	}
	sort(arr.begin(), arr.end(), greater<pii>());
	
	int num;
	for (int i = 0; i < k; i++) {
		cin >> num;
		c[num]++;
	}


	
	ll sum = 0;
	for (auto i : arr) {

		auto it = c.lower_bound(i.second);

		if (it == c.end()) continue;

		sum += i.first;
		it->second--;
		if (it->second == 0)
			c.erase(it);

		if (c.empty()) break;
	}
	cout << sum;
}