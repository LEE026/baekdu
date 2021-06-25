#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int Find(vector<int>& parent,int x) {
	//0�� ������ �𸣴� ���� -1�� ������ �ƴ� ����
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
	else{//b�� -1�� ��쿡�� pa�� -1�� �Ǿ� ������ �ƴ� ������ ��
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
	//������ �ƴ� ���� ����
	for (int i = 0; i < m; i++) {
		cin >> num;
		if (num == 0) continue;

		cin >> party[i];//parent�� �ڱ� �ڽ����� �����Ǽ� �ȳ����°� ���� �Ͱ� ���� Ȯ���� ����
		for (int j = 1; j < num; j++) {
			cin >> input;
			Union(parent, party[i], input);
		}
	}
	int result = 0;
	//����Ƽ�� ������ �ƴ� ������ ������ +1
	for (auto p : party) {
		if (p == 0) continue;//0�̶� ��ȣ�� ���⿡ 0�̸� ��Ƽ�� �ƹ��� ��������
		if (Find(parent, p) != -1)
			result++;
	}
	cout << result;
}