#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);


	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> first(n + 1);

		int a, b;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			first[a] = b;
		}


		int result = 0;
		int prev = 987654321;
		for (int i = 1; i <= n; i++) {
			if (prev > first[i]) {
				result++;
				prev = first[i];
			}
		}

		cout << result << "\n";
	}
}