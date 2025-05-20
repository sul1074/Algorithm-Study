#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void bfs(const vector<vector<int>>& graph, vector<int>& dist, vector<bool>& visited) {
	queue<int> q;
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int curr = q.front(); q.pop();

		for (int neighbor : graph[curr]) {
			if (visited[neighbor]) continue;

			q.push(neighbor);
			dist[neighbor] += dist[curr] + 1;
			visited[neighbor] = true;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n + 1);
	vector<int> dist(n + 1, 0);
	vector<bool> visited(n + 1, false);

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bfs(graph, dist, visited);

	auto it = max_element(dist.begin(), dist.end());
	int maxIdx = it - dist.begin();
	int maxDist = *it;
	int sameDistNum = count(dist.begin(), dist.end(), maxDist);

	cout << maxIdx << ' ' << maxDist << ' ' << sameDistNum << '\n';

	return 0;
}
