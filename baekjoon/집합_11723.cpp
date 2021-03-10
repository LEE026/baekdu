#include<iostream>
#include<string>
#include<set>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int m;
	set<int> S; set<int>::iterator iter;
	string str;
	int num;

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> str;
		if (str == "add") {
			cin >> num;
			S.insert(num);
		}
		else if (str == "remove") {
			cin >> num;
			iter = S.find(num);
			if (iter != S.end()) {
				S.erase(iter);
			}
		}
		else if (str == "check") {
			cin >> num;
			iter = S.find(num);
			if (iter != S.end()) {
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else if (str == "toggle") {
			cin >> num;
			iter = S.find(num);
			if (iter != S.end()) {
				S.erase(iter);
			}
			else
			{
				S.insert(num);
			}
		}
		else if (str == "all") {
			bool in[21] = { false };
			for (iter=S.begin(); iter != S.end(); iter++)
			{
				in[*iter] = true;
			}
			for (int j = 1; j <= 20; j++)
			{
				if (!in[j]) S.insert(j);
			}
		}
		else if (str == "empty") {
			S.clear();
		}
	}
}