#include<iostream>
#include<queue>
using namespace std;


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	
	int t;
	int n, m;
	int num;
	int count;
	cin >> t;
	for (int k = 0; k < t; k++)
	{
		priority_queue<int> pq;
		queue<pair<int, int>> q;
		count = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> num;
			q.push({ num,i });
			pq.push(num);
		}
		
		//�߿䵵�� 1~9�̱⿡ �ð��� ����������
		pair<int, int> tmp;
		while (!q.empty())
		{
			tmp = q.front(); q.pop();//�� ���� ����
			if (tmp.first == pq.top()) {//���� ū�Ÿ�
				pq.pop(); count++;
				if (tmp.second == m) {//���� ã�� �ε����� ���
					cout << count << "\n";
					break;
				}
			}
			q.push(tmp);
		}
	}
}