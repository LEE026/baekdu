#include<iostream>
#include<string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	string s;
	int t;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> s;
		int vcount = 0;
		for (char i:s)
		{
			if (i == '(') {
				vcount++;
			}
			else
			{
				vcount--;
				if (vcount < 0) {
					break;
				}
			}
		}
		if (vcount == 0) {
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	
}