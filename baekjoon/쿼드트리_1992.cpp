#include<iostream>
#include<string>
using namespace std;

string d[64];

void quadTree(int i, int j, int n) {
	
	char color = d[i][j];
	for (int k = i; k < i+n; k++)
	{
		for (int l = j; l < j+n; l++)
		{
			if (color != d[k][l]) {
				int size = n / 2;
				cout << "(";
				quadTree(i, j, size);
				quadTree(i, j+size, size);
				quadTree(i+size, j, size);
				quadTree(i+size, j+size, size);
				cout << ")";
				return;
			}
		}
	}
	cout << color;

	
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		
		cin >> d[i];
	}

	quadTree(0, 0, n);
}