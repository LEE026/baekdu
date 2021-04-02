#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int testcase;
	int n;
	string arrstr;
	string order;
	cin >> testcase;
	for (int t = 0; t < testcase; t++) {
		cin >> order;
		cin >> n;
		cin >> arrstr;
		vector<int> arr;
		
		int tmp = 0;
		

		//문자열로 입력받은 거 배열로 변경
		for (int i = 1; i < arrstr.length(); i++) {
			if (arrstr[i] >= '0' && arrstr[i] <= '9') {
				tmp = tmp * 10 + (arrstr[i] - '0');
			}
			else {
				arr.push_back(tmp);
				tmp = 0;
			}
		}

		bool error=false;
		bool dir = true;//true일때가 정상방향
		int l = 0;
		int r = n - 1;
		for (auto o : order) {
			if (o == 'R') {
				dir = !dir;
			}
			else if (o == 'D') {
				if (l > r) {
					error = true;
					break;
				}
				if (dir) {
					l++;
				}
				else {
					r--;
				}
			}
		}

		if (error)
			cout << "error\n";
		else {
			cout << "[";
			if (dir) {
				for (int i = l; i < r; i++) {
					cout << arr[i] << ",";
				}
				if(l<=r)
					cout << arr[r];
			}
			else {
				for (int i = r; i > l; i--) {
					cout << arr[i] << ",";
				}
				if (l <= r)
					cout << arr[l];
			}
			cout<< "]\n";
		}
	}
}