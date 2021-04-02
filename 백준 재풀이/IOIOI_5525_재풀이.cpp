#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	int m;
	string s;

	cin >> n >> m >> s;

	int i = 0;
	for (; i < m && s[i] != 'I'; i++);//O°Ç³Ê¶Ù±â
	char c[2] = { 'I','O' };
	int len = 0;
	int cnt = 0;
	for (; i < m; i++) {
		if (c[len % 2] == s[i]) {
			len++;
		}
		else {
			//cout << len << " ";
			cnt += max((len - 1) / 2-n+1,0);
			len = 1;
			for (; i < m && s[i] != 'I'; i++);//O°Ç³Ê¶Ù±â
		}
	}
	cnt += max((len - 1) / 2 - n + 1, 0);
	cout << cnt;

}