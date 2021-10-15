#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>

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
	vector<int> arr(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	//모든 팰린드롬 찾기
	vector<vector<bool>> palin(n + 1, vector<bool>(n + 1));
	for (int i = 1; i <= n; i++) {
		int l = i;
		int r = i;

		while (1<=l&&r<=n)
		{
			if (arr[l] != arr[r]) break;
			palin[l][r] = true;
			l--; r++;
		}

		l = i - 1;
		r = i;
		while (1 <= l && r <= n)
		{
			if (arr[l] != arr[r]) break;
			palin[l][r] = true;
			l--; r++;
		}
	}


	//질문응답
	int m;
	cin >> m;
	int a, b;
	while (m--)
	{
		cin >> a >> b;
		cout << (palin[a][b]) << "\n";
	}

}