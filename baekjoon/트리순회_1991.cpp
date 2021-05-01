#include<iostream>
#include<vector>
using namespace std;

void pre(vector<vector<char>>& tree, char node) {
	if (node == '.')
		return;

	cout << node;
	pre(tree, tree[node-'A'][0]);
	pre(tree, tree[node-'A'][1]);
}
void in(vector<vector<char>>& tree, char node) {
	if (node == '.')
		return;

	
	in(tree, tree[node - 'A'][0]);
	cout << node;
	in(tree, tree[node - 'A'][1]);
}
void post(vector<vector<char>>& tree, char node) {
	if (node == '.')
		return;


	post(tree, tree[node - 'A'][0]);
	post(tree, tree[node - 'A'][1]);
	cout << node;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<char>> tree(n, vector<char>(2));

	char a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		tree[a - 'A'][0]=b;
		tree[a - 'A'][1]=c;
	}

	pre(tree, 'A');	cout << "\n";
	in(tree, 'A');	cout << "\n";
	post(tree, 'A');
}