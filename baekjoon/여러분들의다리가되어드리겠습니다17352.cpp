#include<iostream>

using namespace std;

int parent[300001];

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
	else
		parent[py] = px;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	int v1, v2;
	for (int i = 0; i < n - 2; i++) {
		cin >> v1 >> v2;
		Union(v1, v2);
	}

	int p = find(1);
	for (int i = 2; i <= n; i++)
	{
		if (p != find(i)) {
			cout << p << " " << find(i);
			break;
		}
	}
}
