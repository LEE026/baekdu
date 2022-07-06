#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define MOD 1000

vector<vector<int>>& mul(vector<vector<int>>& a, vector<vector<int>>& b) {
	int n = a.size();
	int m = a[0].size();
	int k = b[0].size();

	vector<vector<int>>& result = *(new vector<vector<int>>(n, vector<int>(k)));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			for (int x = 0; x < m; x++) {
				result[i][j] += (a[i][x] * b[x][j])%MOD;
				result[i][j] %= MOD;
			}
		}
	}
	return result;
}

vector<vector<int>>& pow(vector<vector<int>>& a, ll n) {
	if (n == 1) {
		return a;
	}
	
	vector<vector<int>>& sub = pow(a, n / 2);
	vector<vector<int>>& result = mul(sub,sub);
	if (n % 2) {
		return mul(result, a);
	}
	else
	{
		return result;
	}

}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	ll n, b;
	cin >> n >> b;
	vector<vector<int>> a(n, vector<int>(n));
	for (auto& row : a) {
		for (auto& i : row) {
			cin >> i;
			i %= MOD;
		}
	}

	vector<vector<int>>& result = pow(a,b);

	for (auto row : result) {
		for (auto i : row) {
			cout << i << " ";
		}
		cout << "\n";
	}
}