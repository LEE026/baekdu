#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	
	int n, m;
	cin >> n >> m;
	vector<int> num(n);
	int cnt = n + m;
	for (auto& i : num) {
		cin >> i;
	}
	sort(num.begin(), num.end());
	while (m--) {
		int a;
		cin >> a;
		if (binary_search(num.begin(),num.end(),a)) {
			cnt-=2;
		}
	}
	
	cout << cnt;
}