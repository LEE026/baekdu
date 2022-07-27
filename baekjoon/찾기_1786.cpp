#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int>& getPi(string& s) {
	int n = s.length();
	vector<int>& pi = *(new vector<int>(n));
	int l = 0;
	for (int i = 1; i < n; i++) {
		while (l > 0 && s[i] != s[l]) {
			l = pi[l - 1];
		}
		if (s[i] == s[l]) {
			pi[i] = ++l;
		}
	}
	return pi;
}

vector<int>& kmp(string& a, string& b) {
	vector<int>& ans = *(new vector<int>());
	vector<int>& pi = getPi(b);
	int n = a.length();
	int m = b.length();
	int l = 0;
	for (int i = 0; i < n; i++) {
		while (l > 0 && a[i] != b[l]) {
			l = pi[l - 1];
		}
		l += (a[i] == b[l]);
		if (l == m) {
			ans.push_back(i-l+2);
			l = pi[l - 1];
		}
	}
	return ans;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	string a, b;
	getline(cin, a);
	getline(cin, b);

	vector<int>& ans = kmp(a, b);

	cout << ans.size() << "\n";
	for (auto i : ans) {
		cout << i << " ";
	}
}