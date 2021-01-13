#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

int parent[300001];
int ncount[300001];

int find(int x) {
	if (x == parent[x])
		return x;
	else
		return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
	int px = find(x);
	int py = find(y);
	if (px == py)
		return;
	else {
		ncount[px] += ncount[py];
		parent[py] = px;
	}
}


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	map<string, int> m;
	int totalcount;

	int t;
	int f;
	string s1, s2;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> f;
		totalcount = 1;
		for (int j = 0; j < f; j++)
		{
			cin >> s1 >> s2;
			if (m.count(s1) == 0) {
				m[s1] = totalcount;
				parent[totalcount] = totalcount;
				ncount[totalcount] = 1;
				totalcount++;
			}
			if (m.count(s2) == 0) {
				m[s2] = totalcount;
				parent[totalcount] = totalcount;
				ncount[totalcount] = 1;
				totalcount++;
			}
			Union(m[s1], m[s2]);

			cout << ncount[find(m[s1])]<<"\n";
		}

		m.clear();

	}
}