#include<iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	vector<int> squares;
	cin >> n;

	vector<int> num(n+2, 4);
	int squar = sqrt(n);
	num[0] = 1; 
	num[1] = 1;
	squares.push_back(1);
	for (int i = 2; i <= n; i++) {
		
		if (num[i] > 2) {
			for (int j : squares) {
				if (j > i) break;
				if (num[i] > num[i - j] + 1) {
					num[i] = num[i - j] + 1;
					if (num[i] == 2) break;
				}
			}
		}
		if (i <= squar) {
			num[i*i] = 1;
			num[i*i+1] = 2;
			squares.push_back(i*i);
		}
	}

	cout << num[n];

}