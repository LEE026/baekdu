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

	//�ִ�ġ�� k�� ���� �� ����
	int l = 1,r = k;

	while (l<r)
	{
		
		int mid = l + (r - l) / 2;
		int cnt = mid / n * n;//mid/n�� ������ mid���� ������ ���ٴ� n��
		

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