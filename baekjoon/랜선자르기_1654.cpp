#include<iostream>
using namespace std;

int num[10001];

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	long long n, k, result=0;
	long long left = 1, right = 1;//left1บฮลอ
	long long mid = 0;



	cin >> k >> n;

	for (int i = 0; i < k; i++)
	{
		cin >> num[i];
		if (right < num[i]) {
			right = num[i];
		}
	}
	int amount;
	while (left<=right)
	{
		amount=0;
		mid = (left + right) / 2;

		for (int i = 0; i < k; i++)
		{
			amount += num[i] / mid;
		}

		if (amount >= n) {
			if (result < mid) result = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << result;

}