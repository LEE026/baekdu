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

	int n, c;
	cin >> n >> c;
	vector<int> houses(n);
	for (auto& i : houses) {
		cin >> i;
	}
	sort(houses.begin(), houses.end());


	int l = 1;
	int r = houses[n - 1] - houses[0];

	int maxv = 0;
	while (l<=r)
	{
		int mid = (l + r) / 2;

		int prev = 0;
		int cnt = 1;
		for (int i = 1; i < n;i++) {
			prev += houses[i] - houses[i - 1];
			if (prev >= mid) {
				cnt++;
				prev = 0;
			}
		}

		if (cnt < c) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
			maxv = mid;
		}
	}

	cout << maxv;

}