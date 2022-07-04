#include<iostream>
#include<algorithm>
#include<vector>

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
	vector<int> nums(n);
	vector<int> prev(n);	//nums의 인덱스
	vector<int> len;		//nums의 값으로 저장
	vector<int> lenIdx;	//nums의 인덱스로 저장


	for (auto& i : nums) {
		cin >> i;
	}

	for (int i = 0; i < n; i++) {
		int num = nums[i];

		int idx = lower_bound(len.begin(), len.end(), num) - len.begin();

		if (idx == len.size()) {
			len.push_back(num);
			lenIdx.push_back(i);
		}
		else if (len[idx] > num) {
			len[idx] = num;
			lenIdx[idx] = i;
		}

		prev[i] = (idx - 1 < 0) ? -1 : lenIdx[idx - 1];
	}

	vector<int> result;
	int last = lenIdx.back();
	while (last != -1)
	{
		result.push_back(nums[last]);
		last = prev[last];
	}

	cout << result.size() << "\n";
	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i] << " ";
	}
}