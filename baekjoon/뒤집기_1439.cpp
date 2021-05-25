#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int num[2] = { 0 };
	string s;
	cin >> s;
	num[s[0] - '0']++;
	for (int i = 1; i < s.length(); i++) {
		if (s[i - 1] != s[i]) {
			num[s[i] - '0']++;
		}
	}

	cout << min(num[0], num[1]);
}