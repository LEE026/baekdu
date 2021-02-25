#include<iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	long long n;
	cin >> n;

	long long sum = 2;
	int amount = 1;
	while (n>=sum)
	{
		sum += 6 * amount;
		amount++;
	}
	cout << amount;
}