#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

class segTree
{
private:
	vector<ll> tree;
	int last;

	ll makeTree(vector<ll>& nums, int left, int right, int now) {
		if (left == right) {
			tree[now] = nums[left];
		}
		else {
			int mid = (left + right) / 2;
			tree[now] = makeTree(nums, left, mid, now * 2) + makeTree(nums, mid + 1, right, now * 2 + 1);
		}
		return tree[now];
	}

	ll change(int idx, ll num, int left, int right, int now) {
		if (idx < left || right < idx) return 0LL;

		ll c = 0;
		if (left == right) {
			c = num - tree[now];
		}
		else {
			int mid = (left + right) / 2;
			c = change(idx, num, left, mid, now * 2) + change(idx, num, mid + 1, right, now * 2 + 1);
		}
		tree[now] += c;
		return c;
	}

	ll getV(int l, int r, int left, int right, int now) {
		if (right < l || r < left) return 0LL;
		if (l <= left && right <= r) return tree[now];

		int mid = (left + right) / 2;
		ll res = getV(l, r, left, mid, now * 2) + getV(l, r, mid + 1, right, now * 2 + 1);

		return res;
	}

public:
	segTree(vector<ll>& nums) {
		tree.resize(nums.size() * 4 + 1);
		last = nums.size() - 1;
		makeTree(nums, 0, last, 1);
	}

	void changeNum(int idx, ll num) {
		change(idx, num, 0, last, 1);
	}

	ll getValue(int l, int r) {
		return getV(l, r, 0, last, 1);
	}

};


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	vector<ll> nums(n);
	for (auto& i : nums) {
		cin >> i;
	}
	segTree seg(nums);

	int a, b;
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b;
		if (a == 1) {
			ll c;
			cin >> c;
			seg.changeNum(b - 1, c);
		}
		else if (a == 2) {
			int c;
			cin >> c;
			cout << seg.getValue(b - 1, c - 1) << "\n";
		}
	}
}