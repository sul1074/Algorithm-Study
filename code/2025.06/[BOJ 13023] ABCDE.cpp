#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(const vector<vector<int>>& friends, vector<bool>& visited,
	int depth, int curr) {

	if (depth == 5) return true;

	for (auto neighbor : friends[curr]) {
		if (visited[neighbor]) continue;

		visited[neighbor] = true;

		if (dfs(friends, visited, depth + 1, neighbor)) return true;

		visited[neighbor] = false;
	}

	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> friends(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;

		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	bool isValid = false;
	for (int i = 0; i < n; ++i) {
		vector<bool> visited(n, false);
		visited[i] = true;

		if (dfs(friends, visited, 1, i)) {
			isValid = true;
			break;
		}
	}

	if (isValid) cout << 1;
	else cout << 0;
	cout << '\n';

	return 0;
}
