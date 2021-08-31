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

	int n, m;
	cin >> n >> m;
	vector<int> cnt(m + 1);

	ll result = 0;

	int input;
	int num = 0;

	for (int i = 0; i < n; i++) {
		cin >> input;
		num = (num + input) % m;

		if (num == 0) result++;

		result += cnt[num];
		cnt[num]++;
	}


	cout << result;


}