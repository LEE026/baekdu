#include<iostream>
using namespace std;

int tree[10000001];

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	int left = 0, right = 0;
	int maxHight=0;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> tree[i];
		if (tree[i] > right)
			right = tree[i];
	}

	int mid;
	long long sum;
	while (left<=right)
	{
		mid = (left + right) / 2;
		sum = 0;

		for (int i = 0; i < n; i++)
		{
			if (tree[i] - mid > 0)
				sum += tree[i] - mid;
		}

		if(sum>=m){
			if (maxHight < mid) {
				maxHight = mid;
			}
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << maxHight;
}