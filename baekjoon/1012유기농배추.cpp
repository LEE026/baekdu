#include<iostream>
#include<vector>
using namespace std;

bool arr[50][50];
int m, n, k;

void count_bug(int x,int y) {
	
	arr[x][y] = false;
	if (y>0&&arr[x][y-1])
	{
		count_bug(x, y - 1);
	}
	if (y < n-1 && arr[x][y +1])
	{
		count_bug(x, y + 1);
	}

	if (x > 0 && arr[x-1][y])
	{
		count_bug(x-1, y);
	}
	if (x < m-1 && arr[x+1][y])
	{
		count_bug(x+1, y);
	}

}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int result = 0;
	int t;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		result = 0;
		cin >> m >> n >> k;
		
		int x, y;
		for (int j = 0; j < k; j++)
		{
			cin >> x >> y;
			arr[x][y] = true;
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++) {
				if (arr[i][j]) {
					count_bug(i, j);
					result++;
				}
			}
		}

		cout << result<<"\n";
	}

}