#include<iostream>
#include<map>
using namespace std;

map<long long, long long> m;

long long pow(long long a, long long b, long long mod) {
	if (b == 1) {
		return a;
	}
	if (m.find(b) != m.end()) {
		return m[b];
	}

	long long tmp;
	tmp = pow(a, b / 2, mod) * pow(a, (b + 1) / 2, mod) % mod;

	m[b] = tmp;
	return tmp;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	
	m[0] = 1;

	long long a, b, c;
	cin >> a >> b >> c;
	cout << pow(a%c, b, c) % c;
}