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

			//���� �͵��� �� ��, �� ���ʿ� �ִ°ɷ� üũ
			if (field[x][y]!=0 && field[x][y] < shark) {
				iseat = true;
				if (start.first > x) {
					start = { x,y };
				}
				else if (start.first == x && start.second > y) {
					start = { x,y };
				}
			}
			if (iseat) continue; //�ѹ��̶� ������ ����ĭ Ȯ�� ���ʿ�

			//�̵�
			for (int j = 0; j < 4; j++) {
				int nx = x + xd[j];
				int ny = y + yd[j];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

				//������ ������ üũ �������� �̵��� üũ
				if (!visit[nx][ny] && field[nx][ny] <= shark) {
					q.push({ nx,ny });
					visit[nx][ny] = true;
				}
			}
		}

		//�Ծ�����
		if (iseat) {
			int x = start.first;
			int y = start.second;
			field[x][y] = 0;
			eat++;
			start = { n,n };
			iseat = false;
			//����
			if (eat == shark) {
				shark++;
				eat = 0;
			}

			//bfs�ٽ� ���� ���� ����
			setfalse(visit);
			visit[x][y] = true;
			q = queue<pair<int, int>>();
			q.push({ x,y });

			//��� ������Ʈ
			result += day;
			day = 0;
		}
		else
			day++;
	}
	cout << result;

}