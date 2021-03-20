#include<iostream>
using namespace std;

int num[3] = { 0 };
int n;
int paper[2187][2187];

void paperCheck(int i, int j, int s) {
	if (i < 0 || j < 0 || i >= n || j >= n)
		return;

	int pre = paper[i][j];
	for (int k = i; k < s + i; k++) {
		for (int l = j; l < s + j; l++) {
			if (pre != paper[k][l]) {
				int size = s / 3;
				paperCheck(i, j, size);
				
				paperCheck(i + size, j, size);
				paperCheck(i + size*2, j, size);
				
				paperCheck(i, j + size, size);
				paperCheck(i, j + size*2, size);

				paperCheck(i + size, j + size, size);
				paperCheck(i + size*2, j + size, size);
				
				paperCheck(i + size, j + size*2, size);
				paperCheck(i + size*2, j + size*2, size);
				return;
			}
		}
	}
	num[pre + 1]++;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);


	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> paper[i][j];
		}
	}

	paperCheck(0, 0, n);

	for (auto i : num) {
		cout << i << "\n";
	}
}