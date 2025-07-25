#include <iostream>
#include <vector>

using namespace std;

int k, nodeNum;
int visitOrder[1023] = { -1 };

void construct(vector<vector<int>>& tree, int depth, int left, int right) {
	if (depth > k - 1 || left > right) return;

	int mid = (left + right) / 2;
	tree[depth].push_back(visitOrder[mid]);

	construct(tree, depth + 1, left, mid - 1);
	construct(tree, depth + 1, mid + 1, right);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k;
	nodeNum = (1 << k) - 1;
	for (int i = 0; i < nodeNum; ++i) {
		cin >> visitOrder[i];
	}

	vector<vector<int>> tree(k);
	construct(tree, 0, 0, nodeNum);

	for (auto row : tree) {
		for (auto col : row) {
			cout << col << ' ';
		}
		cout << '\n';
	}

	return 0;
}
