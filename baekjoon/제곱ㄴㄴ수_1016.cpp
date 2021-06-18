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
			//제곱수의 배수는 확인해줄 필요가 없다.(한 수의 배수는 그 수의 약수의 배수이기도 하기에)
			for (ll j = sqr; j <= last; j += sqr) {
				check[j] = false;
			}

			//min에서 가장 가까운 sqr의 배수에서 시작
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