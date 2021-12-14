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
	//b�� ��迭 �ϸ� �ȵȴٰ� ������ a�� ��迭 �Ұ��
	//b�� ��迭 �ѰͰ� ���̰� ���⿡ ��� ���� 
	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());//���� ����

	int s = 0;
	for (int i = 0; i < n; i++) {
		s += a[i] * b[i];
	}

	cout << s;
}