#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<string> pan(n);
	for (int i = 0; i < n; i++) {
		cin >> pan[i];
	}

	int minv = 987654321;
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {

			int b_start = 0, w_start = 0;
		
			for (int k = i; k < i + 8; k++) {
				bool w = (k-i)%2==0;
				for (int l = j; l < j + 8; l++) {
					if ((pan[k][l] == 'W') == w)
						b_start++;
					else
						w_start++;

					w = !w;
				}
			}

			minv = min(minv, min(b_start, w_start));
		}
	}

	cout << minv;
}