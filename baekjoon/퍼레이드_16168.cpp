#include<iostream>
#include<vector>
using namespace std;


int find(vector<int>& parent,int x) {
	if (parent[x] == -1) {
		return x;
	}
	return parent[x] = find(parent, parent[x]);
}

void Union(vector<int>& parent,int& total, int x, int y) {
	int px = find(parent, x);
	int py = find(parent, y);
	if (px == py)
		return;

	parent[py] = px;
	total--;
}

//오일러 경로
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int v, e;
	cin >> v >> e;
	vector<int> cnt(v);//각 정점의 차수를 계산
	vector<int> parent(v,-1);//유니온 파인드로 연결환인을 위해 사용


	int v1, v2;
	for (int i = 0; i < e; i++) {
		cin >> v1 >> v2;
		cnt[v1-1]++;
		cnt[v2-1]++;
		Union(parent, v, v1 - 1, v2 - 1);
	}
	int odd=0;
	for (auto i : cnt) {
		if (i % 2 == 1)
			odd++;
	}

	//차수가 홀수인 정점이 2개이거나 0개이면 오일러 경로 존재
	//*전부짝수면 오일러 회로 존재
	cout << (v == 1 && (odd == 2 || odd == 0) ?"YES":"NO");
}