#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;



int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
	vector<int> result(n);

	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		while (!pq.empty() && pq.top().first < num) {
			result[pq.top().second] = num;
			pq.pop();
		}

		pq.push({ num,i });
	}

	while (!pq.empty()) {
		result[pq.top().second] = -1;
		pq.pop();
	}

	for (auto i : result) {
		cout << i << " ";
	}
}