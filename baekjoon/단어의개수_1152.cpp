#include<iostream>
#include<string>
using namespace std;



int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	string s;
	int c = 0;
	getline(cin, s);

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ') c++;
	}
	if (s[0] == ' ') c--;
	if (s[s.length() - 1] == ' ')c--;
	cout << c + 1;
}