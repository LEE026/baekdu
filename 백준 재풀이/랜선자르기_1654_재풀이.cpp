#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int k, n;
	cin >> k >> n;

	long long l = 1,r=1;
	vector<long long> len(k);
	for (int i = 0; i < k; i++) {
		cin >> len[i];
		if (r < len[i]) {//�ִ밪ã��
			r = len[i];
		}
	}

	long long mid, result = 1;
	long long sum; //1�ϰ�� ���ϰ� ���� ���� ����� �� �� �� ����
	while (l<=r)
	{
		sum = 0;
		mid = (l + r) / 2;
		for (auto i : len) {
			sum += i / mid;
		}

		if (sum >= n) {
			result = max(result, mid);
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << result;


	
}