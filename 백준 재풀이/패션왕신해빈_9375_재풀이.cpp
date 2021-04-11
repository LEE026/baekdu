#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int testcase;
	int n;
	string s1, s2;

	cin >> testcase;
	for (int t = 0; t < testcase; t++) {
		cin >> n;
		map<string, int> m;
		for (int i = 0; i < n; i++) {
			cin >> s1 >> s2;
			m[s2]++;
		}
		int result = 1;
		for (auto i : m) {
			result *= i.second+1;
			//cout << i.first << ":" << i.second << "\n";
		}
		cout << result - 1 << "\n";
	}
}