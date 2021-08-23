#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int,int>> piii;
typedef pair<ll, ll> pll;

#define NOT 0

int Find(vector<int>& parent, int x) {
	if (parent[x] == NOT) {
		return x;
	}
	parent[x] = Find(parent, parent[x]);
	return parent[x];
}

void Union(vector<int>& parent, int x, int y) {
	int px = Find(parent, x);
	int py = Find(parent, y);

	parent[py] = px;
}


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> parent(n + 1, NOT);
	vector<piii> edge(m);

	for (auto& i : edge) {
		cin >> i.second.first >> i.second.second >> i.first;//{ºñ¿ë,{x,y}}
	}

	sort(edge.begin(), edge.end());

	int result = 0;
	for (auto e : edge) {
		int x = e.second.first;
		int y = e.second.second;
		if (Find(parent, x) != Find(parent, y)) {
			Union(parent, x, y);
			result += e.first;
		}
	}

	cout << result;
}