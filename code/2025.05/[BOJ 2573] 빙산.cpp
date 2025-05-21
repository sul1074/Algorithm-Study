#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int n, m;

typedef pair<int, int> Pos;

bool isIn(int n, int m, int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m;
}

void bfsCheckIce(const vector<vector<int>>& ice, vector<vector<bool>>& visited, Pos p) {	
	queue<Pos> q;
	q.push(p);

	while (!q.empty()) {
		Pos curr = q.front(); q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = curr.first + dx[i];
			int ny = curr.second + dy[i];

			if (!isIn(n, m, nx, ny) || visited[nx][ny] || ice[nx][ny] == 0) continue;

			q.push({ nx, ny });
			visited[nx][ny] = true;
		}
	}
}

int getIceNum(const vector<vector<int>>& ice) {
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	int cnt = 0;

	for (int i = 0; i < ice.size(); ++i) {
		for (int j = 0; j < ice[0].size(); ++j) {
			if (visited[i][j] || ice[i][j] == 0) continue;

			bfsCheckIce(ice, visited, { i, j });
			++cnt;
		}
	}

	return cnt;
}

void melt(vector<vector<int>>& ice) {
	vector<vector<int>> meltInfo(n, vector<int>(m, 0));

	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			if (ice[r][c] == 0) continue;

			for (int i = 0; i < 4; ++i) {
				int nx = r + dx[i];
				int ny = c + dy[i];

				if (!isIn(n, m, nx, ny) || ice[nx][ny] > 0) continue;

				++meltInfo[r][c];
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (ice[i][j] == 0) continue;

			ice[i][j] = max(0, ice[i][j] - meltInfo[i][j]);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int ans = 0;
	cin >> n >> m;

	vector<vector<int>> ice(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> ice[i][j];
		}
	}

	while (getIceNum(ice) == 1) {
		melt(ice);
		++ans;
	}

	if (getIceNum(ice) > 1) cout << ans << '\n';
	else cout << 0 << '\n';

	return 0;
}
