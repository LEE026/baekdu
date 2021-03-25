#include<iostream>
#include<queue>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	bool graph[100][100];

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	int i, j, k;
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			if (i == k) continue;
			for (j = 0; j < n; j++) {
				if (graph[i][k] && graph[k][j])
					graph[i][j] = true;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << graph[i][j]<<" ";
		}
		cout << "\n";
	}
}