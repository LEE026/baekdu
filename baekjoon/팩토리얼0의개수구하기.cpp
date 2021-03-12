#include<iostream>
#include<string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	int two = 0;
	int five = 0;
	cin >> n;
	
	for (int i = 2; i <= n; i++)
	{
		for (int tmp = i; tmp>0 && tmp % 2==0; tmp/=2)
		{
			two++;
		}
		for (int tmp = i; tmp > 0 && tmp % 5 == 0; tmp /= 5)
		{
			five++;
		}
	}
	
	//cout << two << " " << five << "\n";
	cout << ((two > five) ? five: two);

}