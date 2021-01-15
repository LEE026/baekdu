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
		/*map[]은 없는 값일 경우 0이 반환되고
		map[k]=a는 없을 경우k를 key로하고 a를 value로 하는 노드를 insert하기에 이렇게 하게됨
		*Count[num]++ 나 Count[num]+=1둘 모두 아래와 같이 작동 
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
