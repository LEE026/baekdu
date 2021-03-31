#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool in[8];

void print(vector<int>& v, int m, int cnt,vector<int>& list) {
	if (m == cnt) {
		for (auto i:list) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		if (!in[i]) {
			list[cnt] = i;
			in[i] = true;
			print(v, m, cnt + 1, list);
			in[i] = false;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	
	
	cin >> n >> m;
	vector<int> v(n);
	vector<int> list(m);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	//중복제거
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	print(v, m, 0, list);
}
