#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

string dp[13] = { "-","- -","","","","","","","","","","","" };

string cantor(int n) {
	if (dp[n] != "")
		return dp[n];
	string s = "";
	for (int i = 0; i < pow(3,n-1); i++)
	{
		s.append(" ");
	}

	return cantor(n - 1) + s + cantor(n - 1);
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);


	int n;
	while (true)
	{
		cin >> n;
		if (cin.eof())
			break;
		cout << cantor(n)<<"\n";
	}
		
	
	


}

