#include<iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int cnt[6] = { 1,1,2,2,2,8 };
	int input;
	for (int i = 0; i < 6; i++) {
		cin >> input;
		cout << cnt[i] - input << " ";
	}
}