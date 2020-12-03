#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	priority_queue<pair< int, int>> pq;

	int n;
	cin >> n;

	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num == 0) {
			/*출력확인용
			cout << "= ";*/
			if (pq.empty())
				cout << "0\n";
			else 
			{
				cout << -pq.top().second << "\n";
				pq.pop();
			}
		}
		else
		{
			pq.push(pair<int,int>(-abs(num),-num));
		}
	}
}