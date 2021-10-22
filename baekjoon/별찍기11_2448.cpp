#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void printStar(vector<string>& print, int i, int j, int n) {
	if (n == 3) {
		print[i][j] = '*';
		print[i + 1][j - 1] = print[i + 1][j + 1] = '*';
		for (int k = 0; k < 5; k++) {
			print[i + 2][j - 2 + k] = '*';
		}
	}
	else {
		int halfN = n / 2;
		printStar(print, i, j, halfN);
		printStar(print, i + halfN, j - halfN, halfN);
		printStar(print, i + halfN, j + halfN, halfN);
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<string> print(n, string(n * 2 - 1, ' '));

	printStar(print, 0, n - 1, n);

	for (auto& i : print) {
		cout << i << "\n";
	}
}