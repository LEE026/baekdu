#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	int minarr[3] = { 0 };
	int maxarr[3] = { 0 };
	int tmp[3];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp[0] >> tmp[1] >> tmp[2];

		//max
		int tmp1 = max(maxarr[0], maxarr[1]);
		int tmp2 = max(maxarr[1], maxarr[2]);

		maxarr[0] = tmp1+tmp[0];
		maxarr[1] = max(tmp1,tmp2)+tmp[1];
		maxarr[2] = tmp2+tmp[2];

		//min
		tmp1 = min(minarr[0], minarr[1]);
		tmp2 = min(minarr[1], minarr[2]);

		minarr[0] = tmp1+tmp[0];
		minarr[1] = min(tmp1, tmp2)+tmp[1];
		minarr[2] = tmp2+tmp[2];
	}
	cout << max(maxarr[0], max(maxarr[1], maxarr[2])) << " ";
	cout << min(minarr[0], min(minarr[1], minarr[2]));

}