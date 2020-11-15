#include<iostream>
#include<map>
using namespace std;

long long c;
long long a;
map<int, int> m;

map<int, int>::iterator it;

long long one;
long long mul(int b) {
	if (b == 1) return one;

	if ((it = m.find(b)) != m.end()) {
		return (long long)(it->second);
	}
	else
	{
		if (b % 2 == 0) {//Â¦¼ö
			long long temp = (mul(b / 2)*mul(b / 2)) % c;
			m.insert(pair<int, int>(b, temp));
			return temp;
		}
		else {//È¦¼ö
			long long temp = ((a*mul(b / 2))%c*mul(b / 2)) % c;
			m.insert(pair<int, int>(b, (int)temp));
			return temp;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int b;

	cin >> a >> b >> c;
	one = (int)(a%c);
	cout << mul(b);

}