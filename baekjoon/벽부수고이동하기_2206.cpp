#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

vector<vector<int>> visit;//0아무도 안들림, 1: 한번 부신애만 들림, 2: 한번도 안부신애만 들림

struct point
{
	int x;
	int y;
	bool b;
};

inline void check(vector<string>& field,queue<point>& q, int x, int y, bool b) {
	if (field[x][y] == '1') {
		if (!b && visit[x][y]<2) {
			q.push({ x,y,true });
			visit[x][y] = 2;
		}
	}
	else {

		if (b) {
			if (visit[x][y] != 0) return;
			visit[x][y] = 1;
		}
		else {
			if (visit[x][y]==2) return;
			visit[x][y] = 2;
		}
		q.push({ x,y,b });
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	

	vector<string> field(n);
	for (int i = 0; i < n; i++) {
		cin >> field[i];
	}
	
	visit=vector<vector<int>>(n, vector<int>(m, 0));

	queue<point> q;
	q.push({0,0,false});

	int result = 1;
	while(!q.empty()) {
		int size = q.size();
		
		for (int i = 0; i < size; i++) {
			point now = q.front(); q.pop();
			if (now.x == n - 1 && now.y == m - 1) {
				cout << result;
				return 0;
			}

			//상하좌우 이동
			if (now.x > 0) {
				check(field, q, now.x - 1, now.y, now.b);
			}

			if (now.x < n-1) {
				check(field, q, now.x + 1, now.y, now.b);
			}

			if (now.y > 0) {
				check(field, q, now.x, now.y - 1, now.b);
			}

			if (now.y< m - 1) {
				check(field, q, now.x, now.y + 1, now.b);
			}


		}
		result++;
	}
	cout << -1;




}