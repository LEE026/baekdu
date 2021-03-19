#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	map<string, string> passwordList;

	string url, password;

	int n, m;
	cin >> n>>m;

	for (int i = 0; i < n; i++) {
		cin >> url >> password;
		passwordList[url] = password;
	}

	for (int i = 0; i < m; i++) {
		cin >> url;
		cout<<passwordList[url]<<"\n";
	}




}