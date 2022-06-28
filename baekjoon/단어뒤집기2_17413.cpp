#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

typedef long long ll;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	string s;
	getline(cin, s);

	
	int i = 0;
	int n = s.length();
	int l = 0;
	while (i < n)
	{
		int c = s[i];
		if (c == '<'|| c == ' ') {
			reverse(s.begin() + l, s.begin() + i);
			if(c=='<')
				for (; s[i] != '>'; i++);
			l = i+1;
		}
		i++;
	}
	reverse(s.begin() + l, s.begin() + i);

	cout << s;
}