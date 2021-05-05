#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	vector<int> ladder_snake(101);//둘중하나만 존재 가능하기에 따로 둘 필요 없음

	cin >> n >> m;
	int x, y;
	for (int i = 0; i < n+m; i++) {
		cin >> x >> y;
		ladder_snake[x] = y;
	}
	
	queue<int> q;
	q.push(1);
	int cnt = 0;
	while (!q.empty())
	{
		cnt++;
		int size = q.size();
		for (int i = 0; i < size; i++) {
			bool no = true;
			int num = q.front(); q.pop();

			if (num == 100) {
				cout << cnt-1;
				return 0;
			}

			for (int j = 6; j >= 1; j--) {
				//bfs특성상 한번 간곳은 또가도 의미 없음
				if (num + j > 100 || ladder_snake[num + j] == -1) continue;
				
				if (ladder_snake[num+j] != 0) {
					q.push(ladder_snake[num + j]);
					ladder_snake[num + j] = -1;
				}
				else if (ladder_snake[num + j]==0 && no)
				{
					q.push(num + j);
					ladder_snake[num + j] = -1;
					no = false;
				}

			}
		}
	}
	cout << -1;
}