#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int arr[2][3] = { 0 };//0:r 1:g 2:b
	int n;
	cin >> n;


	int* temp;//좀더 빠르게 참조하기 위함
	for (int i = 1; i <= n; i++) {
		cin >> arr[i % 2][0] >> arr[i % 2][1] >> arr[i % 2][2];
		temp = arr[(i - 1) % 2];
		

		arr[i % 2][0] += min(temp[1], temp[2]);
		arr[i % 2][1] += min(temp[0], temp[2]);
		arr[i % 2][2] += min(temp[0], temp[1]);

	}
	cout << min(arr[n % 2][0], min(arr[n % 2][1], arr[n % 2][2]));

}