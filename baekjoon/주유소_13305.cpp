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
	vector<ll> road(n);
	ll cost=1987654321;

	for (int i = 0; i < n - 1; i++) {
		cin >> road[i];
	}

	ll res = 0;
	ll input;
	//각 도로를 그 도로 이전에 충전할 수 있었던 기름중 가장 저렴한 기름으로 주행하면 됨
	for (int i = 0; i < n; i++) {
		cin >> input;
		cost = min(cost, input);
		res += cost * road[i];
	}
	cout << res;
}