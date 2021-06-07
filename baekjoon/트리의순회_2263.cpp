#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef vector<int>::iterator iter;

void makeTree(vector<pair<int, int>>& tree, vector<int>& post, vector<iter>& in_idx,int& idx, iter start, iter end) {

	auto root = in_idx[post[idx]];

	if (root + 1 != end) {
		idx--;
		tree[*root].second = post[idx];
		makeTree(tree, post,in_idx, idx, root + 1, end);
	}

	if (root != start) {
		idx--;
		tree[*root].first = post[idx];
		makeTree(tree, post, in_idx, idx, start, root);
	}
}

void pre(vector<pair<int, int>>& tree, int root) {
	if (root == 0)
		return;

	cout << root << " ";
	pre(tree, tree[root].first);
	pre(tree, tree[root].second);
	
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> in(n);
	vector<iter> in_idx(n+1);
	vector<int> post(n);
	for (int i = 0; i < n; i++) {
		cin >> in[i];
		in_idx[in[i]] = in.begin() + i;
	}
	for (int i = 0; i < n; i++) {
		cin >> post[i];
	}
	
	//트리제작
	vector<pair<int, int>> tree(n + 1);
	int idx = n-1;
	makeTree(tree, post, in_idx, idx, in.begin(), in.end());
	pre(tree, post.back());


}