#include<iostream>
#include<vector>
using namespace std;


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m, b;
	int min = 2100000000;
	int minHeight;
	
	
	cin >> n >> m >> b;
	vector<int> ground(n*m);
	for (int i = 0; i < ground.size(); i++)
	{
		cin >> ground[i];
	}


	for (int i = 0; i <= 256; i++)
	{
		int subB = b;
		int time = 0;
		for (int j = 0; j < ground.size(); j++)
		{
			int num = ground[j] - i;
			if (num > 0) {
				time += 2*num;
				subB+=num;
			}
			else {
				time += -num;
				subB += num;//numÀÌ -ÀÓ
			}
		}
		if (subB >= 0 && min >= time) {
			min = time;
			minHeight = i;
		}
	}

	cout << min << " " << minHeight;
}