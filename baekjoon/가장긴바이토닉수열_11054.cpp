#include<iostream>

using namespace std;


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	int a[1002] = { 0 };
	int front[1001] = { 0 };
	int back[1001] = { 0 };

	cin >> n;

	int num;
	int max = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++)
	{
		max = 0;
		for (int j = 1; j < i; j++)
		{
			if (a[j] < a[i]&&front[j]>max)//새로 넣은 값이 이전의 값보다 크고 순서가 max보다 뒤일때
				max = front[j];
		}
		front[i] = max+1;
	}

	for (int i = n; i > 0; i--)
	{
		max = 0;
		for (int j = n; j > i; j--)
		{
			if (a[j] < a[i]&&back[j]>max)//새로 넣은 값이 이전의 값보다 크고 순서가 max보다 뒤일때
				max = back[j];
		}
		back[i] = max+1;
	}
	
	/*for (int i = 1; i <= n; i++)
	{
		cout << front[i] << " ";
	}
	cout << "\n";
	for (int i = 1; i <=n; i++)
	{
		cout << back[i] << " ";
	}
	cout << "\n";*/

	max = 0;
	for (int i = 1; i < n + 1; i++)
	{
		if (max < front[i]+back[i])
		{
			max = front[i] + back[i];
		}
	}



	cout << max-1;

}