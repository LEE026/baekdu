#include<iostream>
#include<vector>
#include<algorithm>
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
	vector<int> arr(n+1);


	for (int i = 1; i <= n;i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}


	int minv = INF;
	for (int i = 1; i <= n;i++) {
		int findNum = arr[i] - s;
		//나올 수 없는 값
		if (findNum < 0) continue;

		int pos = lower_bound(arr.begin(), arr.begin() + i, findNum) - arr.begin();

		if (arr[pos] > findNum) pos--;

		minv = min(minv, i - pos);
		
	}
	cout << minv%INF;
}