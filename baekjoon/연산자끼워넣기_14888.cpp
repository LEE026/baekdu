#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int minv = 1987654321;
int maxv = -1987654321;

int twoNumCalc(int a, int b, int num) {
	switch (num)
	{
	case 0:
		return a + b;
	case 1:
		return a - b;
	case 2:
		return a * b;
	case 3:
		return a / b;
	}
	return -1987654321;
}

void calc(vector<int>& nums, vector<int>& op, int idx, int result) {
	if (idx == nums.size()) {
		minv = min(minv, result);
		maxv = max(maxv, result);
	}
	else
	{
		for (int i = 0; i < 4; i++) {
			if (op[i] > 0) {
				op[i]--;
				calc(nums, op, idx + 1, twoNumCalc(result, nums[idx], i));
				op[i]++;
			}
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> nums(n);
	vector<int> op(4);
	for (auto& i : nums) {
		cin >> i;
	}
	for (auto& i : op) {
		cin >> i;
	}

	calc(nums, op, 1, nums[0]);

	cout << maxv << "\n" << minv << "\n";
}