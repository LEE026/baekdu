#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	string s1, s2;
	unordered_map<string, string> list;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s1 >> s2;
		list[s1] = s2;
	}

	for (int i = 0; i < m; i++) {
		cin >> s1;
		cout << list[s1] << "\n";
	}
}