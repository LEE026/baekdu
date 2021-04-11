#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	string s;
	map<string, string> list;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		list[s] = to_string(i);
		list[to_string(i)] = s;
	}
	for (int i = 0; i < m; i++) {
		cin >> s;
		cout << list[s] << "\n";
	}

}