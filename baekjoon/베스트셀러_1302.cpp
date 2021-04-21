#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	string s;
	map<string, int> m;
	string result;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		m[s]++;
	}

	int maxv = 0;
	for (auto i : m) {
		if (maxv < i.second) {
			maxv = i.second;
			result = i.first;
		}
	}

	cout << result;

}