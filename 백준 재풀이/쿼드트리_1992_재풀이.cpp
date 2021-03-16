#include<iostream>
#include<string>
using namespace std;

bool video[64][64];

string quadTree(int i, int j, int n) {
	if (n == 1) return to_string(video[i][j]);

	int size = n / 2;
	string quad[4];
	quad[0] = quadTree(i, j, size);
	quad[1] = quadTree(i, j+size, size);
	quad[2] = quadTree(i+size, j, size);
	quad[3] = quadTree(i+size, j+size, size);

	bool isprint = false;
	for (int k = 1; k < 4; k++) {
		if (quad[0] != quad[k]) {
			isprint = true;
			break;
		}
	}

	if (isprint||quad[0][0]=='(') {
		return "(" + quad[0] + quad[1] + quad[2] + quad[3] + ")";
	}
	else
	{
		return quad[0];
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	string s;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n;j++) {
			video[i][j] = s[j]=='1';
		}
	}

	cout << quadTree(0, 0, n);
	

}




