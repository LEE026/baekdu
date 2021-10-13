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

	for (int i = 2; i*i <= n; i++) {


		while (n%i == 0)
		{
			cout << i << "\n";
			n /= i;
		}
	}

	/*
	n의 제곱근 보다 큰소인수는 최대 1개만 존재 가능
	만일 제곱근보다 큰 약수가 있으면 그 약수로 나눈 몫은
	제곱근 보다 작을 수 밖에 없어서 그전에 이미 나누어 보았을 것이기 때문
	https://www.acmicpc.net/board/view/46874
	*/
	if (n > 1) cout << n << "\n";
}

