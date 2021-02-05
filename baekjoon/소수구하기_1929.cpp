#include<iostream>
#include<cmath>
using namespace std;

bool isnotPrimeNumber[1000001] = { true, true, false };//1은 소수가 아님

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	//에라토스테네스의 체
	int last = floor(sqrt(m));
	for (int i = 4; i <= m; i += 2)
	{
		isnotPrimeNumber[i] = true;
	}
	for (int i = 3; i <= last; i += 2)
	{
		if (!isnotPrimeNumber[i]) {//true인 것을 체크 안함
			for (int j = i+i; j <= m; j+=i)
			{
				isnotPrimeNumber[j] = true;
			}
		}
	}
	//끝
	for (int i = n; i <= m; i++)
	{
		if(!isnotPrimeNumber[i]) cout<<i<<"\n";
	}

}