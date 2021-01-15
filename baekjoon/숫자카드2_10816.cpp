#include<iostream>
#include<map>
using namespace std;


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	map<int, int> Count;
	int n;
	int m;
	int num;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		/*map[]�� ���� ���� ��� 0�� ��ȯ�ǰ�
		map[k]=a�� ���� ���k�� key���ϰ� a�� value�� �ϴ� ��带 insert�ϱ⿡ �̷��� �ϰԵ�
		*Count[num]++ �� Count[num]+=1�� ��� �Ʒ��� ���� �۵� 
		*/
		Count[num] = Count[num] + 1;
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		cout << Count[num] << " ";
	}
}
