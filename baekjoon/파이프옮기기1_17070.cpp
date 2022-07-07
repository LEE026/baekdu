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

	int n;
	cin >> n;
	vector<vector<int>> room(n, vector<int>(n));
	vector<vector<int>> rr(n, vector<int>(n));
	vector<vector<int>> dd(n, vector<int>(n));
	vector<vector<int>> rd(n, vector<int>(n));

	for (auto& row : room) {
		for (auto& i : row) {
			cin >> i;
		}
	}

	for (int i = 1; i < n; i++) {
		if (room[0][i])break;
		rr[0][i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (room[i][j])continue;

			rr[i][j] = rr[i][j - 1] + rd[i][j - 1];

			dd[i][j] = dd[i - 1][j] + rd[i - 1][j];
			
			if (!room[i - 1][j] && !room[i][j - 1])
				rd[i][j] = rr[i - 1][j - 1] + dd[i - 1][j - 1] + rd[i - 1][j - 1];
		}
	}

	cout << rr[n - 1][n - 1] + dd[n - 1][n - 1] + rd[n - 1][n - 1];
}