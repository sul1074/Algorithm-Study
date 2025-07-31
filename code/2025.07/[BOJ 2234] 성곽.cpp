#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int castle[50][50];
bool visited[50][50];

// 서, 북, 동, 남 순
const int dr[4] = { 0, -1, 0, 1 };
const int dc[4] = { -1, 0, 1, 0 };

int dfs(int curr, int depth) {
	int r = curr / 100;
	int c = curr % 100;
	visited[r][c] = true;

	for (int i = 0; i < 4; ++i) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (castle[r][c] & (1 << i) || visited[nr][nc]) continue;

		depth = dfs(nr * 100 + nc, depth + 1);
	}

	return depth;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> castle[i][j];
		}
	}

	int roomNum = 0, largestRoom = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (visited[i][j]) continue;
			largestRoom = max(largestRoom, dfs(i * 100 + j, 1));
			++roomNum;
		}
	}

	int ans = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < 4; ++k) {
				// 외곽 벽 지우는 경우 제외
				if ((i == 0 && k == 1) ||
					(j == 0 && k == 0) ||
					(i == m - 1 && k == 3) ||
					(j == n - 1 && k == 2)) continue;

				if (castle[i][j] & (1 << k)) {
					memset(visited, 0, sizeof(visited));
					castle[i][j] -= (1 << k);
					ans = max(ans, dfs(i * 100 + j, 1));
					castle[i][j] += (1 << k);
				}
			}
		}
	}

	cout << roomNum << '\n';
	cout << largestRoom << '\n';
	cout << ans << '\n';

	return 0;
}
