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

	k--;//������⿡ k-1ĭ�� �ǳʶٴ� �Ͱ�����
	int idx = k;//0���ͽ����ϱ⿡ k-1�ε��� ���� ����
	cout << "<";
	while (true)
	{

		cout << arr[idx]+1;
		for (int i = idx+1; i < n; i++)
		{//��ĭ������(idx�����)
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