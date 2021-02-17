#include<iostream>
#include<stack>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	int num,sum=0;
	stack<int> s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num == 0) {
			s.pop();
		}
		else {
			s.push(num);
		}
	}

	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}

	cout << sum;
}