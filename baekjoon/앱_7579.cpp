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

	int n, m;
	cin >> n >> m;
	//각 열은 필요한 ci 각 셀은 얻은 메모리

	vector<int> mem(n);
	vector<int> c(n);

	for (auto& i : mem) {
		cin >> i;
	}

	int sum = 0;
	for (auto& i : c) {
		cin >> i;
		sum += i;
	}

	vector<int> bag(sum + 1);


	int last = 0;
	//구현의 편의를 위해 1부터 시작
	for (int i = 1; i <= n; i++) {
		int nowmem = mem[i - 1];
		int nowc = c[i - 1];
		last += nowc;

		for (int j = last; j >= nowc; j--) {
			bag[j] = max(bag[j], bag[j - nowc] + nowmem);
		}
	}

	for (int i = 0; i <= last; i++) {
		if (bag[i] >= m) {
			cout << i;
			break;
		}
	}
}