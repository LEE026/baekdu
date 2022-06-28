#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<bool> visit(n + 1);
	for (int i = 2; i<= n; i++) {
		if (!visit[i]) {
			for (int j = i; j <= n; j += i) {
				k-= !visit[j];
				visit[j] = true;
				if (k == 0) {
					cout << j;
					return 0;
				}
			}
		}
	}
}