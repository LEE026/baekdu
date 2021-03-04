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
	vector<pair<int,int>> arr(n);
	vector<int> result(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr.begin(), arr.end(),less<pair<int,int>>());
	//개수 미리 세두기
	int pre = arr[0].first;
	int Count = 0;
	for (int i = 0; i < n; i++)
	{
		if (pre != arr[i].first) {
			Count++;
			pre = arr[i].first;
		}
		result[arr[i].second] = Count;
	}
	//입력순서대로 값저장
	for (int i = 0; i < n; i++)
	{
		cout << result[i] << " ";
	}
}
