#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int t, n;
	string clothes, kind;
	map<string, int> m;
	cin >> t;
	for (int c = 0; c < t; c++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> clothes >> kind;
			//같은 이름의 옷은 존재 x
			m[kind]++;
		}

		map<string, int>::iterator iter;
		int cnt = 1;
		for (iter = m.begin(); iter != m.end(); iter++) {
			cnt *= iter->second + 1;
		}
		cout << cnt - 1<<"\n";
		m.clear();
	}
}