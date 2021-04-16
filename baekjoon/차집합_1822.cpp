#include<iostream>
#include<set>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	set<int> s;
	int a, b;
	int tmp;
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		cin >> tmp;
		s.insert(tmp);
	}
	for (int i = 0; i < b; i++) {
		cin >> tmp;
		auto it=s.find(tmp);
		if (it != s.end()) {
			s.erase(it);
		}
	}

	cout << s.size() << "\n";
	for (auto i : s) {
		cout << i << " ";
	}

}