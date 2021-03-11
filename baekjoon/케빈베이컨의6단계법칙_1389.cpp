#include<iostream>
using namespace std;

#define MAX 987654321

int dist[101][101];

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int v1, v2;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dist[i][j] = MAX;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		dist[i][i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2;
		dist[v1][v2] = 1;
		dist[v2][v1] = 1;
	}

	for (int k = 1; k <= n;k++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (i == k) continue;
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	int min = MAX;
	int minNum = 0;
	int sum;
	for (int i = 1; i <= n; i++)
	{
		sum = 0;
		for (int j = 1; j <= n; j++)
		{
			//모든 애들이 연결되어 있기에 최대치 확인 필요 없음
			sum += dist[i][j];
		}
		if (min > sum) {
			min = sum;
			minNum = i;
		}
	}
	cout << minNum;
}