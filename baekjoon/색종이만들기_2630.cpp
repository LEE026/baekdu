#include<iostream>
using namespace std;

bool color[128][128];
int blue = 0, white = 0;

int paper(int i,int j, int n) {
	if (n == 1)
		return (int)color[i][j];

	int p[4], size = n / 2;
	p[0] = paper(i, j, size);
	p[1] = paper(i+size, j, size);
	p[2] = paper(i, j+size, size);
	p[3] = paper(i+size, j+size, size);

	//p[0]이 -1이 아니고 전부 같은 색일 경우
	if (p[0] != -1 && p[0] == p[1] && p[2] == p[3] && p[0] == p[3])
		return p[0];
	else
	{
		for (int i = 0; i < 4; i++)
		{
			switch (p[i])
			{
			case 0:
				white++;
				break;
			case 1:
				blue++;
				break;
			default:
				break;
			}
		}

		return -1;
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> color[i][j];
		}
	}
	int tmp = paper(0, 0, n);
	switch (tmp)
	{
	case 0:
		white++;
		break;
	case 1:
		blue++;
		break;
	default:
		break;
	}
	cout << white << "\n" << blue << "\n";
}