#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> arr(n+1);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int sum = arr[0];
	int i = 0, j = 0;
	int cnt = 0;

	while (j < n) {
		if (sum == m) {
			cnt++;
			sum -= arr[i];
			i++; j++;
			sum += arr[j];
		}
		else if (sum < m) {
			j++;
			sum += arr[j];
		}
		else
		{
			sum -= arr[i];
			i++;
		}
	}

	cout << cnt;
}