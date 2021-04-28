#include<iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;
	int one, two, three;
	int tmp;
	for (int t = 0; t < testcase; t++) {
		one = two = three = 0;
		for (int i = 0; i < 10; i++) {
			cin >> tmp;

			if (tmp > one) {
				three = two;
				two = one;
				one = tmp;
			}
			else if (tmp > two) {
				three = two;
				two = tmp;
			}
			else if (tmp > three) {
				three = tmp;
			}
		}
		cout << three << "\n";
	}

}