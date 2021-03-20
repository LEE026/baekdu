#include<iostream>
#include<algorithm>//sort�� ����ϱ� ���ؼ� �ʿ�
using namespace std;

int num[100000];

int binarySearch(int n,int x) {
	int mid;
	int l = 0;
	int r = n - 1;

	while (l <= r) {
		mid = (l + r) / 2;

		if (x == num[mid]) {
			return 1;
		}
		else if (x < num[mid]) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return 0;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m,tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);//�������� ����
	

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		cout << binarySearch(n, tmp)<<"\n";
	}
}