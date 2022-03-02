#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define BIAS 4000

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> arr(n);
	vector<int> cnt(8001);
	double sum = 0;

	for (auto& i : arr) {
		cin >> i;
		sum += i;
		cnt[i + BIAS]++;
	}

	//산술평균
	cout << int(round(sum / n)) << "\n";
	
	//중앙값
	int num = 0;
	for (int i = 0; i < cnt.size(); i++) {
		num += cnt[i];
		if (num > n / 2) {
			cout << i - BIAS << "\n";
			break;
		}
	}

	//최빈값, 최빈값이 여러개일때는 최빈값중 중 두번째로 작은 값
	int one = 0;
	int two = 0;
	num = 0;
	for (int i = cnt.size()-1; i >= 0 ; i--) {
		if (cnt[i] == 0) continue;
		if (num < cnt[i]) {
			one = i;
			two = i;
			num = cnt[i];
		}
		else if (num == cnt[i]) {
			two = one;
			one = i;
		}
	}
	cout << (two - BIAS) << "\n";

	//범위
	int minv = 0;
	int maxv = 0;
	for (int i = 0; i < cnt.size(); i++) {
		if (cnt[i]) {
			minv = i;
			break;
		}
	}
	for (int i = cnt.size() - 1; i >= 0; i--) {
		if (cnt[i]) {
			maxv = i;
			break;
		}
	}
	cout << (maxv - minv) << "\n";


}