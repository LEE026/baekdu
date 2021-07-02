#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

inline int rclock(vector<vector<int>>& room, int place) {
	int prev = 0;
	int row = room.size();
	int col = room[0].size();
	//오른쪽
	for (int j=1;j< col; j++) {
		swap(room[place][j], prev);
	}
	//위
	for (int i=place-1; i >= 0; i--) {
		swap(room[i][col-1], prev);
	}
	//왼쪽
	for (int j=col-2; j >=0; j--) {
		swap(room[0][j], prev);
	}
	//아래
	for (int i = 1; i <place; i++) {
		swap(room[i][0], prev);
	}
	return prev;
}
inline int clock(vector<vector<int>>& room, int place) {
	int prev = 0;
	int row = room.size();
	int col = room[0].size();
	//오른쪽
	for (int j = 1; j < col; j++) {
		swap(room[place][j], prev);
	}
	//아래
	for (int i = place+1; i < row; i++) {
		swap(room[i][col-1], prev);
	}
	//왼쪽
	for (int j = col - 2; j >= 0; j--) {
		swap(room[row-1][j], prev);
	}
	//위
	for (int i = row-2; i > place; i--) {
		swap(room[i][0], prev);
	}
	
	return prev;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int r, c, time;
	cin >> r >> c >> time;
	int cleaner;//공기청정기의 아래칸위치
	vector<vector<int>> room[2];
	room[0] = vector<vector<int>>(r, vector<int>(c));
	room[1] = vector<vector<int>>(r, vector<int>(c));

	int total = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> room[0][i][j];
			if (room[0][i][j] == -1)
				cleaner = i;
			else
				total += room[0][i][j];
		}
	}

	int rowd[] = { 1,-1,0,0 };
	int cold[] = { 0,0,1,-1 };

	for (int t = 0; t < time; t++) {
		vector<vector<int>>& now = room[t % 2];
		vector<vector<int>>& next = room[(t+1) % 2];
		next[cleaner][0] = -1;
		next[cleaner - 1][0] = -1;

		//확산
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (next[i][j] == -1) continue;

				int amount = now[i][j] / 5;

				for (int d = 0; d < 4; d++) {
					int nrow = i + rowd[d];
					int ncol = j + cold[d];
					
					if (nrow < 0 || nrow >= r || ncol < 0 || ncol >= c) continue;
					if (next[nrow][ncol] == -1) continue;

					next[nrow][ncol] += amount;
					now[i][j] -= amount;
				}

				next[i][j] += now[i][j];
				now[i][j] = 0;
			}
		}
		//공기청정기
		total -= rclock(next, cleaner - 1);
		total -= clock(next, cleaner);
	}

	

	cout << total;

}