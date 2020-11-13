#include<iostream>
#include<list>
#include<queue>
using namespace std;

list<int> l[100001];
int parent[100001] = { 0 };

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	
	int n;//노드의 개수
	cin >> n;

	//그래프 제작
	int v1,v2;
	for (int i = 0; i < n-1; i++)
	{
		cin >> v1 >> v2;
		l[v1].push_back(v2);
		l[v2].push_back(v1);
	}

	//bfs
	queue<int> q;
	int now;
	q.push(1);

	while (!q.empty())
	{
		now = q.front(); q.pop();
		for (list<int>::iterator iter = l[now].begin(); iter != l[now].end(); iter++)
		{
			if ((*iter) != parent[now]) {
				parent[*iter] = now;
				q.push(*iter);
			}

		}

	}

	//출력
	for (int i = 2; i <= n; i++)
	{
		cout << parent[i] << "\n";
	}
}