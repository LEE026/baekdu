#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	string a, b;
	vector<int> result;
	cin >> a >> b;
	int carry = 0;
	int i = a.length() - 1, j = b.length() - 1;
	int sum;

	while (i >= 0 || j >= 0) {
		sum = carry;
		if (i >= 0)
			sum += a[i--] - '0';
		if (j >= 0)
			sum += b[j--] - '0';

		carry = sum / 10;
		result.push_back(sum % 10);
	}
	if (carry)
		cout << 1;
	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i];
	}
}