#include<iostream>
#include<string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	string s1, s2;
	cin >> s1 >> s2;

	if (s1.length() >= s2.length())
		cout << "go";
	else
		cout << "no";
}