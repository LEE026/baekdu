#include<iostream>
#include<string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int num=0;
	int op = 1;
	int result=0;
	int tmp = 0;
	string s;
	cin >> s;

	for (char c : s)
	{
		if (c >= '0'&&c <= '9') {
			//¼ýÀÚ
			num *= 10;
			num += c - '0';
		}
		else if (c=='-') {
			num += tmp;
			result += op * num;
			op = -1;
			num = 0;
			tmp = 0;
		}
		else {
			tmp += num;
			num = 0;
		}
	}
	num += tmp;
	result += op * num;

	cout << result;
}