#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	string s1, s2;
	cin >> s1 >> s2;

	vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1));
	
	//lcs구하기
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			dp[i][j] = max(max(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1] + (s1[i - 1] == s2[j - 1]));
		}
	}

	/*cout << "0 ";
	for (auto i : s2) {
		cout << i << " ";
	}
	cout << "\n";
	for (int i = 1; i <= s1.size(); i++) {
		cout << s1[i - 1] << " ";
		for (int j = 1; j <= s2.size(); j++) {
			cout<<dp[i][j]<<" ";
		}
		cout << "\n";
	}*/

	string result="";
	int j = s2.length();
	for (int i = s1.length(); i > 0; i--) {
		if (dp[i][j] != dp[i-1][j]) {
			for (; j > 0 && dp[i][j] == dp[i][j - 1]; j--);//+1된 지점으로
			result = s1[i-1] + result;
			j--;
		}
	}
	cout << result;
}