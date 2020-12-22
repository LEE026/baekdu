#include<iostream>
#include<algorithm>
using namespace std;

int pow2n[16] = { 1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768 };

int Z(int n, int r, int c);

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	int r, c;
	cin >> n >> r >> c;

	cout << Z(n, r, c);
}

int Z(int n, int r, int c) 
{
	if (n == 1) {
		return r * 2 + c;
	}
	int div = pow2n[n - 1];
	
	if (r < div) {
		if (c < div) {
			return Z(n - 1, r, c);
		}
		else
		{
			return div*div + Z(n - 1, r, c-div);
		}
	}
	else
	{
		if (c < div) {
			return div * div *2 +Z(n - 1, r-div, c);
		}
		else
		{
			return div * div * 3 + Z(n - 1, r - div, c-div);
		}
	}
	
}