#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string dp[101][101];

string add(string a, string b) {
	int carry = 0;
	string result;
	int i = a.size() - 1, j = b.size() - 1;
	while (i >= 0 || j >= 0||carry) {

		if (i >= 0) {
			carry += a[i] - '0';
			i--;
		}
		if (j >= 0) {
			carry += b[j] - '0';
			j--;
		}
		result.push_back((carry % 10)+'0');
		carry /= 10;
	}
	reverse(result.begin(), result.end());
	return result;
}

//100 C 50은 너무 큼
string combination(int a, int b) {
	if (a == b || b == 0) return "1";
	if (a == b - 1 || b == 1)return to_string(a);

	//중복 제거
	string& res = dp[a][b];
	if (res != "")
		return res;
	res = add(combination(a - 1, b), combination(a - 1, b - 1));


	return res;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	cout << combination(n, min(m, n - m));

}