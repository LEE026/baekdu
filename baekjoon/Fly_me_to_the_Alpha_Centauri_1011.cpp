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

	int tc;
	cin >> tc;
	while (tc--)
	{
		int x, y;
		cin >> x >> y;
		int diff = y - x;

		int minv = diff;

		diff -= 2;
		for (int i = 2; diff >= i; i++) {
			int tmp = (i - 1) * 2 + diff / i + (diff%i != 0);
			minv = min(minv, tmp);
			diff -= i * 2;
		}
		cout << minv << "\n";
	}
}