#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

//102로 하게된 이유는 범위를 벗어났는지 확인을 안해도 되게하기 위함
bool canvisit[102][102] = { false };
int Count[102][102];




int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;


	cin >> n >> m;
	string row;
	for (int i = 1; i <= n; i++)
	{
		cin >> row;
		for (int j = 1; j <= m; j++)
		{
			canvisit[i][j] = row[j-1] == '1';
			Count[i][j] = 987654321;
		}
	}

	queue<pair<int, int>> q;
	q.push({ 1,1 });
	Count[1][1] = 1;

	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		canvisit[i][j] = false;
		int nowCount = Count[i][j];

		if (canvisit[i - 1][j] && Count[i-1][j]>nowCount+1) {
			q.push({ i - 1,j });
			Count[i - 1][j] = nowCount + 1;
		}

		if (canvisit[i + 1][j] && Count[i + 1][j] > nowCount + 1) {
			q.push({ i + 1,j });
			Count[i + 1][j] = nowCount + 1;
		}

		if (canvisit[i][j - 1] && Count[i][j -1] > nowCount + 1) {
			q.push({ i,j - 1 });
			Count[i][j-1] = nowCount + 1;
		}

		if (canvisit[i][j+1] && Count[i][j+1] > nowCount + 1) {
			q.push({ i,j+1 });
			Count[i][j+1] = nowCount + 1;
		}
	}
	

	cout << Count[n][m];


}