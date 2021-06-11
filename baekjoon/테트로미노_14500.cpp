#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define INF 987654321

int xd[] = { -1,0,1,0 };//ㅜㅓㅗㅏ
int yd[] = { 0,1,0,-1 };

int checkt(vector<vector<int>>& paper, int i, int j) {
	
	int tmp = paper[i][j] + paper[i + 1][j] + paper[i][j + 1] + paper[i][j - 1];//ㅜ
	int maxv = tmp;
	for (int k = 1; k < 4; k++) {
		tmp -= paper[i + xd[k]][j + yd[k]];
		tmp += paper[i + xd[k - 1]][j + yd[k - 1]];
		maxv = max(maxv, tmp);
	}

	return maxv;
}

int checktet(vector<vector<int>>& paper, int i, int j, int prev,int len) {
	if (len==3 || paper[i][j] < 0)
		return paper[i][j];

	int maxv = -INF;
	int tmp;
	for (int k = 0; k < 4; k++) {
		if (k != prev) {
			tmp=checktet(paper, i + xd[k], j + yd[k], (k + 2) % 4,len+1);
			maxv = max(maxv, tmp);
		}
	}

	return paper[i][j] + maxv;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> paper(n+2, vector<int>(m+2,-INF));//-로 둘러싸서 벗어나는건 무시하도록

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> paper[i][j];
		}
	}

	int maxv = 0;
	int tmp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			tmp = checktet(paper, i, j, -1, 0);
			tmp=max(tmp,checkt(paper, i, j));
			maxv = max(maxv, tmp);
		}
	}

	cout << maxv;
}