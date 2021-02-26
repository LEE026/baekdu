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
		
		//중요도가 1~9이기에 시간이 터지지않음
		pair<int, int> tmp;
		while (!q.empty())
		{
			tmp = q.front(); q.pop();//맨 앞을 뽑임
			if (tmp.first == pq.top()) {//가장 큰거면
				pq.pop(); count++;
				if (tmp.second == m) {//내가 찾는 인덱스면 출력
					cout << count << "\n";
					break;
				}
			}
			q.push(tmp);
		}
	}
}