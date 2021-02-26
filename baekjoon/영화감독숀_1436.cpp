#include<iostream>
#include<string>
using namespace std;

char num[1000] = { 0 };

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	
	int n;
	int num=666;
	int count = 1;
	cin >> n;
	while (count<n)
	{
		num++;
		if (to_string(num).find("666")!=string::npos) {
			count++;
		}
	}
	cout << num;
}