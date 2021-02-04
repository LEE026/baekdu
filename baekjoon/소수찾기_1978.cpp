#include<iostream>
#include<cmath>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	//에라토스테네스의 체
	bool isnotPrimeNumber[1001] = { true, true, false };//1은 소수가 아님
	double last = sqrt(1000);
	for (int i = 4; i <= 1000; i+=2)
	{
		isnotPrimeNumber[i] = true;
	}
	for (int i = 3; i <= last; i+=2)
	{
		if (!isnotPrimeNumber[i]) {//true인 것을 체크 안함
			for (int j = 2; i*j <= 1000; j++)
			{
				isnotPrimeNumber[i*j] = true;
			}
		}
	}
	//끝

	int n;
	int Count = 0;
	int num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (!isnotPrimeNumber[num]) Count++;
	}

	cout << Count;

}