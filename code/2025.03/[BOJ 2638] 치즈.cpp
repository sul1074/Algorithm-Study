#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };

typedef pair<int, int> Pos;

bool isIn(int r, int c, int n, int m) {
	return r >= 0 && r < n && c >= 0 && c < m;
}

bool isCheeseExist(const vector<vector<int>>& map, Pos size) {
	for (int i = 0; i < size.first; ++i) {
		for (int j = 0; j < size.second; ++j) {
			if (map[i][j] == 1) return true;
		}
	}

	return false;
}

void bfs(vector<vector<int>>& map, vector<vector<int>>& visited, Pos size) {
	queue<Pos> q;
	q.push({ 0, 0 });
	++visited[0][0];

	while (!q.empty()) {
		Pos curr = q.front(); q.pop();

		for (int i = 0; i < 4; ++i) {
			int nr = curr.first + dr[i];
			int nc = curr.second + dc[i];

			if (!isIn(nr, nc, size.first, size.second)) continue;
			if (map[nr][nc] == 0 && visited[nr][nc] > 0) continue;
			
			++visited[nr][nc];

			if (map[nr][nc] == 0) q.push({nr, nc});
			if (visited[nr][nc] >= 2) map[nr][nc] = 0;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, ans = 0;
	cin >> n >> m;

	vector<vector<int>> map(n, vector<int>(m));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}

	while (isCheeseExist(map, { n, m })) {
		vector<vector<int>> visited(n, vector<int>(m, 0));

		bfs(map, visited, { n, m });

		++ans;
	}

	cout << ans << '\n';

	return 0;
}
