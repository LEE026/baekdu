#include<iostream>
#include<queue>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int n,a;
	int tmp;
	priority_queue<int> pq;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 0) {
			if (pq.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();

			}
		}
		else {
			for (int j = 0; j < a; j++) {
				cin >> tmp;
				pq.push(tmp);
			}
		}

	}

}