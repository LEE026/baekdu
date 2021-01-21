#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<pair<int, int>> p(n);
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].first >> p[i].second;
	}

	sort(p.begin(), p.end(), less<pair<int, int>>());

	for (int i = 0; i < n; i++)
	{
		cout << p[i].first << " " << p[i].second << "\n";
	}
}