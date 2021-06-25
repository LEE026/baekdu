#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int Find(vector<int>& parent,int x) {
	//0은 진실을 모르는 집합 -1은 진실을 아는 집합
	if (parent[x] == -1) {
		return -1;
	}
	if (parent[x] == 0) return x;

	return parent[x] = Find(parent, parent[x]);
}

void Union(vector<int>& parent, int a, int b) {
	int pa = Find(parent, a);
	int pb = Find(parent, b);

	if (pa == pb) return;

	if (pa == -1) {
		parent[pb] = pa;
	}
	else{//b가 -1일 경우에는 pa가 -1이 되어 진실을 아는 집합이 됨
		parent[pa] = pb;
	}
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> parent(n+1);
	int num, input;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> input;
		parent[input] = -1;
	}
	vector<int> party(m);
	//진실을 아는 집합 제작
	for (int i = 0; i < m; i++) {
		cin >> num;
		if (num == 0) continue;

		cin >> party[i];//parent가 자기 자신으로 설정되서 안끝나는걸 막는 것과 이후 확인을 위함
		for (int j = 1; j < num; j++) {
			cin >> input;
			Union(parent, party[i], input);
		}
	}
	int result = 0;
	//그파티에 진실을 아는 집합이 없으면 +1
	for (auto p : party) {
		if (p == 0) continue;//0이란 번호는 없기에 0이면 파티에 아무도 없던거임
		if (Find(parent, p) != -1)
			result++;
	}
	cout << result;
}