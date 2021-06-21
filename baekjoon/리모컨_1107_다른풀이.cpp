#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

void check(vector<bool>& button, int& minv,int goal, int num, int len) {
	if (len > 0 && num == 0) return;
	for (int i = 0; i <= 9; i++) {
		if (button[i]) {
			int tmp = num * 10 + i;
			minv = min(minv, abs(goal - tmp) + len+1);
			if (len < 6)
				check(button, minv, goal, tmp, len + 1);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<bool> button(10,true);
	int input;
	for (int i = 0; i < m; i++) {
		cin >> input;
		button[input] = false;
	}
	int minv = abs(n - 100);
	check(button, minv, n, 0, 0);
	cout << minv;
}