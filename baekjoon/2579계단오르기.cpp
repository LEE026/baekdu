#include<iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;//계단개수
	
	int num[301] = { 0 };//점수
	int dp[301] = { 0 };//총점수
	bool pre[301] = { true };
	
	cin >> n;
	//첫게단 초기화
	cin >> num[1];
	dp[1] = num[1];
	pre[1] = false;

	for (int i = 2; i <= n; i++) {
		cin >> num[i];

		int tmp;
		//이전이 그이전을 안들고 있으면 뺄필요 없음
		if (pre[i - 1]) {
			tmp = dp[i - 3] + num[i - 1] + num[i];
		}
		else
		{
			tmp = dp[i - 1] + num[i];
		}
	

		if (tmp > dp[i - 2] + num[i]) {			
			dp[i] = tmp;
			pre[i] = true;
		
		}
		else {
			dp[i] = dp[i - 2] + num[i];
			pre[i] = false;
		}

	}

	cout << dp[n];

}