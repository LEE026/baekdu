#include<iostream>
#include<stack>
#include<string>
using namespace std;


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	string s;

	while (true)
	{
		
		getline(cin,s);
		if (s == ".") break;

		stack<char> st;
		bool yes = true;

		for (char c:s)
		{
			if (c == '.') break;

			if (c == '('|| c == '[') {
				st.push(c);
			}
			else if (c == ')') {
				if (!st.empty() && st.top() == '(') {
					st.pop();
				}
				else
				{
					yes = false;
					break;
				}
			}
			else if (c == ']') {
				if (!st.empty() && st.top() == '[') {
					st.pop();
				}
				else
				{
					yes = false;
					break;
				}
			}
		}
		if (yes&&st.empty()) cout << "yes\n";
		else cout << "no\n";


	}

}