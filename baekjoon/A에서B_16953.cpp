#include<iostream>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int a, b;
	cin >> a >> b;
	map<int,int> arr;
	queue<int> q;
	arr[a] = 1;
	q.push(a);
	
	while (!q.empty())
	{
		int now = q.front(); q.pop();
		int nowV = arr[now];
		//cout << now << ":" << nowV << "\n";
		if (now <= b/2 && (arr[now*2]==0||arr[now*2]>nowV+1)) {
			q.push(now * 2);
			arr[now * 2] = nowV + 1;
		}
		if (now <= (b - 1) / 10 && (arr[now * 10 + 1] == 0 || arr[now * 10 + 1] > nowV + 1)) {
			q.push(now * 10 + 1);
			arr[now * 10 + 1] = nowV + 1;
		}
	}

	cout << ((arr[b] == 0) ? -1 : arr[b]);
	
}