#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	map<string, bool> list;
	int n;
	string s1, s2;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s1 >> s2;
		list[s1] = (s2 == "enter");
	}

	auto i = list.end();
	while(i != list.begin()) {
		i--;
		if (i->second)
			cout << i->first << "\n";
	}

}