#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	
	int num;
	bool yes = true;

	bool open = false;
	for (int i = 0; i < n; i++) {
		cin >> num;

		if (num == 0) continue;

		if (num == 1) {
			open = !open;
		}
		else if(num==2 && open){
			open = true;
		}
		else{
			yes = false;
		}

	}

	if (yes&&!open) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}