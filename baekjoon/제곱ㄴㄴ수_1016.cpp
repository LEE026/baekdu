#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long ll;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	ll minv, maxv;
	cin >> minv >> maxv;
	ll last = sqrt(maxv);
	vector<bool> notSquared(maxv - minv + 1LL, true);
	int result = notSquared.size();
	vector<bool> check(last + 1LL, true);

	for (ll i = 2LL; i <= last; i++) {
		if (check[i]) {
			ll sqr = i * i;
			//�������� ����� Ȯ������ �ʿ䰡 ����.(�� ���� ����� �� ���� ����� ����̱⵵ �ϱ⿡)
			for (ll j = sqr; j <= last; j += sqr) {
				check[j] = false;
			}

			//min���� ���� ����� sqr�� ������� ����
			ll plus = (sqr - minv % sqr) % sqr;
			for (ll j = minv+plus; j <= maxv; j += sqr) {
				if (notSquared[j-minv]) {
					notSquared[j-minv] = false;
					result--;
				}
			}
		}
	}
	cout << result;
}