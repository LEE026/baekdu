#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<vector<int>>& mul(vector<vector<int>>& a, vector<vector<int>>& b) {
	int n = a.size();
	int m = a[0].size();
	int k = b[0].size();

	vector<vector<int>>& result = *(new vector<vector<int>>(n, vector<int>(k)));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			for (int x = 0; x < m; x++) {
				result[i][j] += a[i][x] * b[x][j];
			}
		}
	}
	return result;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (auto& row : a) {
		for (auto& i : row) {
			cin >> i;
		}
	}

	cin >> m >> k;
	vector<vector<int>> b(m, vector<int>(k));
	for (auto& row : b) {
		for (auto& i : row) {
			cin >> i;
		}
	}

	vector<vector<int>>& result = mul(a, b);

	for (auto row : result) {
		for (auto i : row) {
			cout << i << " ";
		}
		cout << "\n";
	}
}