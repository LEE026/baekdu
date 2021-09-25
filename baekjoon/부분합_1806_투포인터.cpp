#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define INF 987654321

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, s;
	cin >> n >> s;

	int minv = INF;
	int sum = 0, num;
	vector<int> arr(n);
	for (auto& i : arr) {
		cin >> i;
	}
	arr.push_back(0);
	int i = 0, j = 0;
	while (j<=n)
	{
		if (sum >= s) {
			minv = min(minv, j - i);
			sum -= arr[i];
			i++;
		}
		else {
			sum += arr[j];
			j++;
		}
	}
	cout << minv % INF;
}