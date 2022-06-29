#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int xd[] = {0,0,1,-1};
int yd[] = {1,-1,0,0};

int count(vector<string>& bord,int i, int j) {

	int n = bord.size();
	int cnt = 0;
	
	int row = 1;
	int col = 1;
	for (int k = 1; k < n; k++) {
		if (bord[i][k - 1] == bord[i][k]) {
			col++;
		}
		else {
			cnt = max(cnt, col);
			col = 1;
		}

		if (bord[k - 1][j] == bord[k][j]) {
			row++;
		}
		else {
			cnt = max(cnt, row);
			row = 1;
		}
	}
	cnt = max(cnt, max(row, col));
	return cnt;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<string> bord(n);
	for (auto& row : bord) {
		cin >> row;
	}

	int maxv = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			maxv = max(maxv, count(bord, i, j));

			for (int d = 0; d < 4; d++) {
				if (maxv == n)break;
				int nx = i + xd[d];
				int ny = j + yd[d];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				swap(bord[i][j],bord[nx][ny]);
				maxv = max(maxv, count(bord, nx, ny));
				swap(bord[i][j],bord[nx][ny]);
			}
			if (maxv == n)break;
		}
		if (maxv == n)break;
	}
	cout << maxv;
}