#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, k;
	int idx=0;
	cin >> n >> k;
	k--;
	vector<int> num(n);
	for (int i = 0; i < n; i++)
	{
		num[i]=i;
	}
	auto tmp = num.begin();
	cout << "<";
	while (n>1) {
		idx=(idx+k)%n;
		cout << *(tmp+idx)+1 << ", ";
		num.erase(tmp + idx);
		n--;
	}
	cout << num[0]+1 << ">";
	
}