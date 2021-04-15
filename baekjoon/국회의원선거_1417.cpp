#include<iostream>
#include<queue>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	int dasom;
	int tmp;
	priority_queue<int> pq;
	cin >> n >> dasom;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i < n; i++) {
		cin >> tmp;
		pq.push(tmp);
	}

	int cnt=0;
	while (dasom <= pq.top()) {
		tmp = pq.top(); pq.pop();
		pq.push(tmp - 1);
		dasom++;
		cnt++;
	}

	cout << cnt;
}