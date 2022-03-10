#include<iostream>
#include<string>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	string s;
	cin >> n >> m >> s;
	bool isI = true;
	int cnt = 0;
	int result = 0;
	for (int i = 0; i < m; i++) {
		if ((s[i] == 'I') == isI) {
			isI = !isI;
			cnt++;
		}
		else {
			cnt -= n * 2 + 1;
			if (cnt >= 0) {
				result += 1 + cnt / 2;
			}
			cnt = (s[i]=='I');
			isI = (s[i] != 'I');
		}
	}
	cnt -= n * 2 + 1;
	if (cnt >= 0) {
		result += 1 + cnt / 2;
	}

	cout << result;

}