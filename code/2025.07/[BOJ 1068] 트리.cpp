#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int parent;
	vector<int> child;
};

int ans = 0;

void dfs(const vector<Node>& tree, int target, int curr) {
	if (curr == target) return;

	for (auto ch : tree[curr].child) {
		dfs(tree, target, ch);
	}

	if (tree[curr].child.empty() || 
		(tree[curr].child.size() == 1 && tree[curr].child[0] == target)) ++ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, root = -1;
	cin >> n;

	vector<Node> tree(n);
	for (int i = 0; i < n; ++i) {
		Node node;
		cin >> node.parent;

		tree[i] = node;
		if (node.parent == -1) root = i;
	}

	int target;
	cin >> target;

	for (int i = 0; i < n; ++i) {
		if (tree[i].parent == -1) continue;

		tree[tree[i].parent].child.push_back(i);
	}

	dfs(tree, target, root);

	cout << ans << '\n';

	return 0;
}
