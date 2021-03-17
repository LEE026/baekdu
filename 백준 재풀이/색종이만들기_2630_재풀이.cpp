#include<iostream>
using namespace std;

int white = 0, blue = 0;
int n;
bool paper[128][128];

void paperCheck(int i, int j, int s) {
	if (i < 0 || j < 0 || i >= n || j >= n)
		return;

	bool pre=paper[i][j];
	for (int k = i; k < s+i; k++) {
		for (int l = j; l < s+j; l++) {
			if (pre != paper[k][l]) {
				int size=s/2;
				paperCheck(i, j, size);
				paperCheck(i+size, j, size);
				paperCheck(i, j+size, size);
				paperCheck(i+size, j+size, size);
				return;
			}
		}
	}
	if (pre) blue++;
	else white++;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	
	int num;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			paper[i][j] = num == 1;
		}
	}

	paperCheck(0, 0, n);
	cout << white << "\n" << blue;
}