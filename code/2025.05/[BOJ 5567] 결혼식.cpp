#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(const vector<vector<int>>& friends, vector<bool>& visited, int start) {
	queue<pair<int, int>> q;
	q.push({ start, 0 });
	
	int cnt = 0;
	visited[start] = true;

	while (!q.empty()) {
		auto curr = q.front(); q.pop();

		if (curr.second > 2) continue;

		for (int neighbor : friends[curr.first]) {
			if (visited[neighbor] || curr.second + 1 > 2) continue;

			q.push({ neighbor, curr.second + 1 });
			visited[neighbor] = true;
			++cnt;
		}
	}

	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> friends(n + 1);
	vector<bool> visited(n + 1, false);

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;

		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	cout << bfs(friends, visited, 1) << '\n';

	return 0;
}
