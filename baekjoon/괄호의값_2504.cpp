#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	stack<int> numst;
	stack<char> st;

	string s;
	cin >> s;
	int tmp;
	for (auto c : s) {

		if (c == '(' || c == '[') {
			st.push(c);
			continue;
		}

		if (!st.empty() && st.top() == '0') {
			//0이 연달아 두개가 오지는 않음
			st.pop();
			tmp = numst.top(); numst.pop();
		}
		else {
			tmp = 1;
		}

		
		if (!st.empty() && c==')' && '('==st.top()) {
			tmp *= 2;
			st.pop();
			while (!st.empty() && st.top()=='0')
			{
				tmp += numst.top();
				st.pop(); numst.pop();
			}
			st.push('0');
			numst.push(tmp);
		}
		else if (!st.empty() && c == ']' && '[' == st.top()) {
			tmp *= 3;
			st.pop();
			while (!st.empty() && st.top() == '0')
			{
				tmp += numst.top();
				st.pop(); numst.pop();
			}
			st.push('0');
			numst.push(tmp);
		}
		else {
			cout << 0;
			return 0;
		}
	}
	if (st.size() == numst.size())
		cout << numst.top();
	else
		cout << 0;
}