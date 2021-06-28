#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

inline void setfalse(vector<vector<bool>>& visit) {
	for (int i = 0; i < visit.size(); i++) {
		for (int j = 0; j < visit.size(); j++) {
			visit[i][j] = false;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int>> field(n, vector<int>(n));
	vector<vector<bool>> visit(n, vector<bool>(n));
	queue<pair<int, int>> q;
	pair<int, int> start = { n,n };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> field[i][j];
			if (field[i][j] == 9) {
				q.push({ i,j });
				field[i][j] = 0;
				visit[i][j] = true;
			}
		}
	}
	int result = 0;
	
	int xd[] = { -1,0,0,1 };
	int yd[] = { 0,-1,1,0 };

	int shark = 2;
	int eat = 0;
	int day = 0;
	bool iseat = false;
	while (!q.empty()) {

		int size = q.size();
		for (int i = 0; i < size; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			//먹은 것들중 더 위, 더 왼쪽에 있는걸로 체크
			if (field[x][y]!=0 && field[x][y] < shark) {
				iseat = true;
				if (start.first > x) {
					start = { x,y };
				}
				else if (start.first == x && start.second > y) {
					start = { x,y };
				}
			}
			if (iseat) continue; //한번이라도 먹으면 다음칸 확인 불필요

			//이동
			for (int j = 0; j < 4; j++) {
				int nx = x + xd[j];
				int ny = y + yd[j];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

				//위에서 먹음을 체크 했음으로 이동만 체크
				if (!visit[nx][ny] && field[nx][ny] <= shark) {
					q.push({ nx,ny });
					visit[nx][ny] = true;
				}
			}
		}

		//먹었으면
		if (iseat) {
			int x = start.first;
			int y = start.second;
			field[x][y] = 0;
			eat++;
			start = { n,n };
			iseat = false;
			//성장
			if (eat == shark) {
				shark++;
				eat = 0;
			}

			//bfs다시 돌기 위한 셋팅
			setfalse(visit);
			visit[x][y] = true;
			q = queue<pair<int, int>>();
			q.push({ x,y });

			//결과 업데이트
			result += day;
			day = 0;
		}
		else
			day++;
	}
	cout << result;

}