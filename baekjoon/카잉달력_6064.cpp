#include<iostream>
using namespace std;

int gcd(int a, int b) {
	if (a%b == 0) {
		return b;
	}
	else
		return gcd(b, a%b);
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int testcse;
	int m, n, x, y;
	int destructionDay;
	int day;
	cin >> testcse;
	for (int t = 0; t < testcse; t++) {
		cin >> m >> n >> x >> y;
		destructionDay = m * n / gcd((m > n) ? m : n, (m < n) ? m : n);
		day = x-1;//나머지시 0~n-1이 남기에 -1을 한상태로 계산

		while (true)
		{
			if (day > destructionDay) {
				cout << "-1\n";
				break;
			}
			else if (day % n + 1 == y) {//날자확인을 위해 1 더함
				cout << day+1<<"\n";//정상출력을 위해 +1
				break;
			}
			day += m;
		}
	}

}