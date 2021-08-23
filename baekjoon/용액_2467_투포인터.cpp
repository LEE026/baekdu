#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> arr(n);

	for (auto& i : arr) {
		cin >> i;
	}
	//입력이 오름차순으로 들어오기에 정렬필요 x

	int minv = INT32_MAX;
	pii idx;
	int l = 0, r = n - 1;
	while (l<r)
	{
		int sum = arr[l] + arr[r];
		if (abs(sum) < minv) {
			minv = abs(sum);
			idx = { l,r };
		}

		if (sum < 0) l++;
		else r--;
	}

	cout << arr[idx.first] << " " << arr[idx.second];

}