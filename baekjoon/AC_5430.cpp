#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	bool isfront;
	int d=0;
	int front, back;
	bool error;

	int t, n;
	string p, sarr;
	cin >> t;
	for (int k = 0; k < t; k++) {
		cin >> p >> n;
		cin >> sarr;
		
		isfront = true;
		error = false; d = 0;
		vector<int> arr(n,0);

		int idx = 0;
		for (auto c:sarr) {
			if (c >= '0'&&c <= '9') {
				arr[idx] = arr[idx] * 10 + c - '0';
			}
			else if (c == ',') idx++;
		}
		front = 0;
		back = n-1;

		for (auto c : p) {
			if (c == 'R') {
				isfront = !isfront;
			}
			else {
				if (++d > n) {
					error = true;
					break;
				}
				if (isfront) {
					front++;
				}
				else {
					back--;
				}
			}
		}
		if(error){
			cout << "error\n";
			continue;
		}

		cout << "[";
		if (isfront) {
			for (; front < back; front++) {
				cout << arr[front] << ",";
			}
			if(front<=back)
				cout << arr[front];
		}
		else
		{
			for (; back > front; back--) {
				cout << arr[back] << ",";
			}
			if (front <= back)
				cout << arr[back];
		}
		cout << "]\n";
	}
}