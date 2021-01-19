#include<iostream>
#include<string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int Count[26] = { 0 };
	string s;

	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		//¶ç¾î¾²±â x
		if (s[i] >= 'a') {
			Count[s[i] - 'a']++;
		}
		else
			Count[s[i] - 'A']++;
	}
	int max=0;
	bool isunique = true;
	for (int i = 1; i < 26; i++)
	{
		if (Count[max] <= Count[i]) {
			if (Count[max] == Count[i]) {
				isunique = false;
			}
			else
			{
				max = i;
				isunique = true;
			}
		}
		
	}
	if (isunique)
		cout << (char)('A' + max);
	else
		cout << "?";
}