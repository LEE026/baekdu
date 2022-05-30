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
	vector<int> arr(n);
	for (auto& i : arr) {
		cin >> i;
	}
	sort(arr.begin(), arr.end());

	int m;
	cin >> m;
	while (m--)
	{
		int num;
		cin >> num;
		int cnt = upper_bound(arr.begin(), arr.end(), num) - lower_bound(arr.begin(), arr.end(), num);
		cout << cnt << " ";
	}
}