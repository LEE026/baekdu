#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<pii> arr(n);
	vector<int> result(n + 1);

	for (auto& i : arr) {
		cin >> i.first >> i.second;
	}

	for (int i = 0; i < n; i++) {
		result[i + 1] = max(result[i + 1], result[i]);

		int next = i + arr[i].first;

		if (next <= n) {
			result[next] = max(result[next], result[i] + arr[i].second);
		}
	}

	cout << result[n];

}