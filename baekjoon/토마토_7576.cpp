#include<iostream>
#include<queue>
using namespace std;

int box[1000][1000];
queue<pair<int, int>> q;
int amount = 0;


inline void qPush(int row, int col) {
	q.push({ row,col });
	box[row][col] = 1;
	amount--;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);



	int n, m;//n이 가로 m이 세로로 했음
	int day = 0;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> box[i][j];
			if (box[i][j] == 1) {
				q.push({ i,j });
			}
			else if (box[i][j] == 0) {
				amount++;
			}
		}
	}


	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int row = q.front().first;
			int col = q.front().second;
			q.pop();

			if (0 < row && box[row - 1][col] == 0)
				qPush(row - 1, col);

			if (row < m - 1 && box[row + 1][col] == 0)
				qPush(row + 1, col);

			if (0 < col && box[row][col-1] == 0)
				qPush(row, col - 1);

			if (col < n - 1 && box[row][col+1] == 0)
				qPush(row, col + 1);

		}
		day++;
	}

	if (amount == 0) {
		cout << day - 1;
	}
	else
	{
		cout << "-1";
	}
}