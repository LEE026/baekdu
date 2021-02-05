#include<iostream>
#include<cmath>
using namespace std;

bool isnotPrimeNumber[1000001] = { true, true, false };//1�� �Ҽ��� �ƴ�

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	//�����佺�׳׽��� ü
	int last = floor(sqrt(m));
	for (int i = 4; i <= m; i += 2)
	{
		isnotPrimeNumber[i] = true;
	}
	for (int i = 3; i <= last; i += 2)
	{
		if (!isnotPrimeNumber[i]) {//true�� ���� üũ ����
			for (int j = i+i; j <= m; j+=i)
			{
				isnotPrimeNumber[j] = true;
			}
		}
	}
	//��
	for (int i = n; i <= m; i++)
	{
		if(!isnotPrimeNumber[i]) cout<<i<<"\n";
	}

}