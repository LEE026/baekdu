#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	int num;

	while (n--)
	{
		cin >> num;
		pq.push(num);
	}

	int res = 0;
	while (pq.size()>1)//한개가 남을때 까지
	{
		num = pq.top();
		pq.pop();
		num += pq.top();
		pq.pop();

		res += num;
		pq.push(num);
	}

	cout << res;

}