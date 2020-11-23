#include<iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	bool win[7]={0,1,0,1,1,1,1};
	long long n;
	
	cin >> n;

	if (win[n % 7L])
		cout << "SK";
	else
		cout << "CY";


}