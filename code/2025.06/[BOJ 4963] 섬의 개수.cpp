#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[8] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dy[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };

typedef pair<int, int> Pos;

bool isIn(Pos size, Pos curr) {
	return curr.first >= 0 && curr.first < size.first &&
		curr.second >= 0 && curr.second < size.second;
}

void bfs(vector<vector<int>>& map, Pos size, Pos start) {
	queue<Pos> q;
	q.push(start);
	map[start.first][start.second] = 0;

	while (!q.empty()) {
		Pos curr = q.front(); q.pop();

		for (int i = 0; i < 8; ++i) {
			int nx = curr.first + dx[i];
			int ny = curr.second + dy[i];

			if (!isIn(size, { nx, ny }) || map[nx][ny] == 0) continue;

			q.push({ nx, ny });
			map[nx][ny] = 0;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int w = -1, h = - 1;

	while (1) {
		cin >> w >> h;

		if (w == 0 && h == 0) break;

		int cnt = 0;
		vector<vector<int>> map(h, vector<int>(w));

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (map[i][j] == 0) continue;

				bfs(map, { h, w },  { i, j });
				++cnt;
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}
