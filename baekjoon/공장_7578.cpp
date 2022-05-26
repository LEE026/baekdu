#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


class segTree {
private:
	int size;
	vector<int> arr;
public:
	segTree(int size) {
		this->size = size;
		this->arr = vector<int>(size*4);
	}

	void set(int idx, int value) {
		set(0, size - 1, 1, idx, value);
	}

	int set(int i, int j,int arrIdx, int idx, int value) {
		if (i == j) {
			int val = arr[arrIdx];
			arr[arrIdx] = value;
			return value - val;
		}

		int mid = (i + j) / 2;
		int val;
		if (idx <= mid) {
			val=set(i, mid, arrIdx * 2, idx, value);
		}
		else
		{
			val=set(mid + 1, j, arrIdx * 2 + 1, idx, value);
		}
		arr[arrIdx] += val;
		return val;
	}

	int get(int l,int r) {
		return get(0, size - 1, 1, l, r);
	}

	int get(int i, int j, int arrIdx, int l, int r) {
		if (l == i && r == j)
			return arr[arrIdx];
		if (l <= i && j <= r)
			return arr[arrIdx];

		int mid = (i + j) / 2;
		int sum = 0;
		if (mid < r)
			sum += get(mid + 1, j, arrIdx * 2 + 1, max(l,mid+1), r);
		if (l <= mid)
			sum += get(i, mid, arrIdx * 2, l, min(mid, r));
		return sum;
	}
};

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	segTree seg(n);
	map<int, int> m;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		m[arr[i]] = i;
	}
	
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr[m[num]] = i;
	}

	ll result = 0;

	for (int i = 0; i < n; i++) {
		result += seg.get(arr[i], n-1);
		seg.set(arr[i], 1);
	}

	cout << result;
}