#include<iostream>
#include<stack>

using namespace std;

bool v[200001] = { false };
int number[100000] = { 0 };

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	int idx = 0;
	int num;
	int c=1;
	stack<int> s;

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> number[i];
	}
	for (int i = 0; i < n; i++)
	{
		num=number[i];
		for (; c <= num; c++)
		{
			s.push(c);
			v[idx++] = true;
		}
		if (s.top() != num) {
			cout << "NO";
			return 0;
		}
		s.pop();
		v[idx++] = false;
	}
	for (int i = 0; i < idx; i++)
	{
		if (v[i])
			cout << '+';
		else
			cout << '-';
		cout << '\n';
	}


}