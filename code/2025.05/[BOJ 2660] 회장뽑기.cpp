#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int bfs(const vector<vector<int>>& people, vector<bool>& visited, int start) {
	int depth = 0;
	visited[start] = true;

	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int round = q.size();

		for (int i = 0; i < round; ++i) {
			int curr = q.front(); q.pop();

			for (int neighbor : people[curr]) {
				if (visited[neighbor]) continue;

				q.push(neighbor);
				visited[neighbor] = true;
			}
		}

		++depth;
	}

	return depth - 1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> people(n + 1);
	vector<int> score(n + 1, INT_MAX);

	int a = 1, b = 1;

	while (1) {
		cin >> a >> b;

		if (a == -1 && b == -1) break;

		people[a].push_back(b);
		people[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i) {
		sort(people[i].begin(), people[i].end());
	}

	for (int i = 1; i <= n; ++i) {
		vector<bool> visited(n + 1, false);

		score[i] = bfs(people, visited, i);
	}

	auto it = min_element(score.begin(), score.end());
	int min_score = *it;
	int cnt = count(score.begin(), score.end(), min_score);

	cout << min_score << ' ' << cnt << '\n';
	for (int i = 1; i <= n; ++i) {
		if (score[i] == min_score) cout << i << ' ';
	}
	cout << '\n';

	return 0;
}
