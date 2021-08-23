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

	for(auto& i: arr) {
		cin >> i;
	}
	//입력이 오름차순으로 들어오기에 정렬필요 x

	int minv = INT32_MAX;
	pii res;
	for (int i = 1; i < n; i++) {
		int now = arr[i-1];//현재 값
		int pos = lower_bound(arr.begin() + i, arr.end(), -now)-arr.begin();

		if (pos<n && abs(arr[pos]+now) < minv) {
			minv = abs(arr[pos] + now);
			res = { now,arr[pos] };
		}

		pos--;
		if (pos>=i && abs(arr[pos] + now) < minv) {;
			minv = abs(arr[pos] + now);
			res = { now,arr[pos] };
		}

	}

	cout << res.first << " " << res.second;

}