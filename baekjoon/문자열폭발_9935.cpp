#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	string s, boom;
	cin >> s >> boom;
	int n = s.length();
	int m = boom.length();

	vector<char> result(n+1);
	vector<int> comp(n+1,-1);

	int j = 1;
	int b = 0;
	for (int i = 0; i < n; i++) {
		result[j] = s[i];

		if (result[j] == boom[0]) {
			comp[j] = 0;
			b = 1;
		}
		else if (result[j] == boom[b]) {
			comp[j] = b;
			b++;
		}
		else {
			comp[j] = -1;
			b = 0;
		}

		if (b == m) {
			j -= b;
			b = comp[j]+1;
		}
		j++;
	}


	if (j <= 1) {
		cout << "FRULA";
	}
	else {
		for (int i = 1; i < j; i++) {
			cout << result[i];
		}
	}

}