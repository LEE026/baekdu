#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> arr(n);

	for (auto& i : arr) {
		cin >> i;
	}

	int num = arr[n - 1];
	int result = 0;
	for (int i = n - 2; i >= 0; i--) {
		num--;
		if (arr[i] > num) {
			result += arr[i] - num;
		}
		else {
			num = arr[i];
		}
	}

	cout << result;
}