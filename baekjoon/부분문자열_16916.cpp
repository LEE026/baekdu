#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void check(vector<int>& arr, string& p){
	int n = p.length();
	int j = 0;
	arr[0] = 0;

	for (int i = 1; i < n; i++) {
		if (p[i] == p[j]) {
			j++;
		}
		else if(p[i] == p[0]){
			j = 1;
		}
		else {
			j = 0;
		}
		arr[i] = j;
	}
}

bool in(string& s, string& p) {
	int n = s.length();
	int m = p.length();

	vector<int> arr(m);

	check(arr, p);

	int i = 0, j = 0;

	while (i<n)
	{
		if (s[i] == p[j]) {
			j++;
		}
		else {
			if (j > 0) i--;
			j = arr[max(j-1,0)];
		}
		if (j == m) {
			return true;
		}
		i++;

	}
	return false;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	string s, p;
	cin >> s >> p;

	int n = s.length();
	int m = p.length();

	cout << in(s, p);

}