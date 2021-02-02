#include<iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, k;
	int* arr;
	cin >> n >> k;
	arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = i;
	}

	k--;//당겨지기에 k-1칸을 건너뛰는 것과같음
	int idx = k;//0부터시잣하기에 k-1인덱스 부터 시작
	cout << "<";
	while (true)
	{

		cout << arr[idx]+1;
		for (int i = idx+1; i < n; i++)
		{//한칸씩당기기(idx지우기)
			arr[i - 1] = arr[i];
		}
		

		if (n > 1) {
			cout << ", ";
			idx = (idx + k) % (--n);
		}
		else
		{
			cout << ">";
			break;
		}
	}
	

}