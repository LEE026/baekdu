#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define INF 987654321

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, s;
	cin >> n >> s;

	int minv = INF;
	int sum = 0, num;
	queue<int> q;

	for (int i = 0; i < n; i++) {
		cin >> num;
		sum += num;
		q.push(num);

		if (sum < s) continue;

		while (sum - q.front() >= s)
		{
			sum -= q.front();
			q.pop();
		}
		minv = min(minv, int(q.size()));
	}
	cout << minv % INF;
}