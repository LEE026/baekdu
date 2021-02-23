#include<iostream>
#include<string>
using namespace std;

#define R 31
#define M 1234567891

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	string s;
	int l;
	long long sum;
	long long i;
	cin >> l;
	cin >> s;
	i = 1; sum = 0;
	for (char c : s) {
		sum = (sum+(c - 'a' + 1)*i) % M;
		i = (i*R) % M;
	}
	cout << sum;
}