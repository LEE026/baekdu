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

	int num;
	priority_queue<int> small;
	priority_queue<int, vector<int>, greater<int>> big;
	small.push(-987654321);
	big.push(987654321);

	while (n--) {
		cin >> num;
		if (small.top() < num) big.push(num);
		else small.push(num);

		int diff = small.size() - big.size();
		if (diff > 1) {
			big.push(small.top());
			small.pop();
		}
		else if (diff < -1) {
			small.push(big.top());
			big.pop();
		}

		if (small.size() >= big.size())
			cout << small.top() << "\n";
		else
			cout << big.top() << "\n";
	}
}