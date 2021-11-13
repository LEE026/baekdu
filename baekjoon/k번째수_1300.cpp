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

	int n, k;
	cin >> n >> k;

	//최대치는 k를 넘을 수 없음
	int l = 1,r = k;

	while (l<r)
	{
		
		int mid = l + (r - l) / 2;
		int cnt = mid / n * n;//mid/n개 동안은 mid보다 작은게 각줄당 n개
		

		for (int i = mid/n+1; i <= n; i++) {
			cnt += min(mid / i, n);
		}
		
		if (cnt < k) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
		

	}

	cout << r;
}