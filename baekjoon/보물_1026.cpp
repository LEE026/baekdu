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
	vector<int> a(n);
	vector<int> b(n);

	for (auto& i : a) {
		cin >> i;
	}
	for (auto& i : b) {
		cin >> i;
	}
	//b는 재배열 하면 안된다고 했지만 a를 재배열 할경우
	//b를 재배열 한것과 차이가 없기에 상관 없다 
	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());//역순 정렬

	int s = 0;
	for (int i = 0; i < n; i++) {
		s += a[i] * b[i];
	}

	cout << s;
}