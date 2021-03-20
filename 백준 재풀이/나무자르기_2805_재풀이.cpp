#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int bottom = 0;
	int top;

	int n, m;
	cin >> n >> m;
	
	vector<int> tree(n);
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
		top = max(top, tree[i]);
	}

	int mid;
	long long sum;
	int result = 0;
	while (bottom<=top)
	{
		mid = (bottom + top) / 2;
		sum = 0;

		for (auto t : tree) {
			if (t > mid)
				sum += t - mid;
		}

		if (sum >= m) {
			result = max(result, mid);
			bottom = mid + 1;//현재높이에서는 충분히 나무를 가져갈 수 있기에 더 높여봄
		}
		else {
			top = mid - 1;
		}
	}

	cout << result;
	
	
}