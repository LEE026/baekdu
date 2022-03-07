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
	vector<int> times(n);
	for (auto& time : times) {
		cin >> time;
	}
	sort(times.begin(), times.end());

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += times[i] * (n - i);
	}

	cout << sum;
}