#include <iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;



int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	stack<pair<int, int>> st;
	vector<int> result(n);

	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		while (!st.empty() && st.top().first < num) {
			result[st.top().second] = num;
			st.pop();
		}

		st.push({ num,i });
	}

	while (!st.empty()) {
		result[st.top().second] = -1;
		st.pop();
	}

	for (auto i : result) {
		cout << i << " ";
	}
}