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

//���Ϸ� ���
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int v, e;
	cin >> v >> e;
	vector<int> cnt(v);//�� ������ ������ ���
	vector<int> parent(v,-1);//���Ͽ� ���ε�� ����ȯ���� ���� ���


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

	//������ Ȧ���� ������ 2���̰ų� 0���̸� ���Ϸ� ��� ����
	//*����¦���� ���Ϸ� ȸ�� ����
	cout << (v == 1 && (odd == 2 || odd == 0) ?"YES":"NO");
}