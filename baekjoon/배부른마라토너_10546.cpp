#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	map<string, int> m;
	cin >> n;

	string name;

	for (int i = 0; i < n; i++) {
		cin >> name;
		m[name]++;
	}
	for (int i = 1; i < n; i++) {
		cin >> name;
		m[name]--;
	}
	for (auto i : m) {
		if (i.second != 0) {
			cout << i.first;
			break;
		}
	}
}