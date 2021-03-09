#include<iostream>
#include<queue>
#include<vector>
using namespace std;



int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);


	
	int t;
	int k;
	char s;
	int num;

	cin >> t;
	for (int c = 0; c < t; c++)
	{
		priority_queue<pair<int, int>> max;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min;
		cin >> k;
		int idx = 0;
		vector<bool> used(k, false);
		for (int i = 0; i < k; i++)
		{
			cin >> s >> num;
			if (s == 'I') {
				max.push({ num,idx });
				min.push({ num,idx });
				idx++;
			}
			else
			{
				if (num == 1) {
					while (!max.empty() && used[max.top().second])
					{
						max.pop();
					}
					if (max.empty()) {
						while (!min.empty())
						{
							min.pop();
						}
					}
					else
					{
						used[max.top().second] = true;
						max.pop();
					}
				}
				else {
					while (!min.empty() && used[min.top().second])
					{
						min.pop();
					}
					if (min.empty()) {
						while (!max.empty())
						{
							max.pop();
						}
					}
					else
					{
						used[min.top().second] = true;
						min.pop();
					}
				}
			}
		}
		while (!max.empty() && used[max.top().second])
		{
			max.pop();
		}
		while (!min.empty() && used[min.top().second])
		{
			min.pop();
		}
		if (min.empty() || max.empty())
			cout << "EMPTY\n";
		else {
			cout << max.top().first << " " << min.top().first << "\n";
		}
	}

}