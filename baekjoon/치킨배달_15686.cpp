#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

typedef pair<int, int> pii;
#define INF 987654321

int chickinDist(vector<bool>& in, vector<vector<int>>& dist, int m,int i, int cnt) {
	int r = dist.size();
	int c = dist[0].size();
	if (m == cnt) {
		int v = 0;
		for (int i = 0; i < c; i++) {//모든집에서
			int d = INF;
			for (int j = 0; j < r; j++) {//선택된 치킨집중 가장 짧은 것
				if (in[j])
					d = min(d, dist[j][i]);
			}
			v += d;
		}
		return v;
	}

	if (m-cnt > dist.size()-i)
		return INF;

	int minv = INF;
	in[i] = true;
	minv=min(minv,chickinDist(in, dist, m, i + 1, cnt + 1));
	in[i] = false;
	minv = min(minv, chickinDist(in, dist, m, i + 1, cnt));
	return minv;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<pii> shop;
	vector<pii> house;

	int num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			if (num == 1) {
				house.push_back({ i,j });
			}
			else if (num == 2) {
				shop.push_back({ i,j });
			}
		}
	}

	int r = shop.size();
	int c = house.size();

	vector<vector<int>> dist(r, vector<int>(c));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			dist[i][j] = abs(shop[i].first - house[j].first) + abs(shop[i].second - house[j].second);
		}
	}

	vector<bool> in(r);
	cout << chickinDist(in, dist, m, 0, 0);
}