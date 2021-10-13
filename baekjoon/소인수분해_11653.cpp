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
	n�� ������ ���� ū���μ��� �ִ� 1���� ���� ����
	���� �����ٺ��� ū ����� ������ �� ����� ���� ����
	������ ���� ���� �� �ۿ� ��� ������ �̹� ������ ������ ���̱� ����
	https://www.acmicpc.net/board/view/46874
	*/
	if (n > 1) cout << n << "\n";
}

