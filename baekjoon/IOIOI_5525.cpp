#include<iostream>
#include<string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	string s;

	int now = 1;
	int result = 0;
	int idx;

	cin >> n >> m;
	cin >> s;

	for (idx = 0; idx < m; idx++) {
		if (s[idx] == 'I') break;
	}

	for (int i = idx+1; i < m; i++)
	{
		now++;
		if (s[i - 1] == s[i]) {
			now = 1;//I일 때까지 지나칠꺼라
			for (; i<m && s[i] == 'O'; i++);
		}
		else if (now == 3 + (n - 1) * 2) {
			now -= 2;//I에서 끝나기에
			result++;
		}
	}

	cout << result;

	
}