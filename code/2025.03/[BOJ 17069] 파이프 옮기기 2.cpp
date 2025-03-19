#include <iostream>
#include <algorithm>

using namespace std;

enum Dir {
	HOR, // 가로
	VER, // 세로 
	DIA // 대각
};

long long dp[33][33][3];
int map[33][33];

bool isIn(int r, int c, int n) {
	return r >= 0 && r < n && c >= 0 && c < n;
}

long long dfs(int r, int c, Dir dir, int n) {
	if (r == n - 1 && c == n - 1) return 1;
	if (dp[r][c][dir] != -1) return dp[r][c][dir];

	int nr = r;
	int nc = c + 1;
	dp[r][c][dir] = 0;

	// 가로 이동
	if (dir == HOR || dir == DIA) {
		if (isIn(nr, nc, n) && map[nr][nc] == 0) {
			dp[r][c][dir] += dfs(nr, nc, HOR, n);
		}
	}

	// 세로 이동
	if (dir == VER || dir == DIA) {
		nr = r + 1;
		nc = c;

		if (isIn(nr, nc, n) && map[nr][nc] == 0) {
			dp[r][c][dir] += dfs(nr, nc, VER, n);
		}
	}

	// 대각 이동
	nr = r + 1;
	nc = c + 1;
	
	if (isIn(nr, nc, n) && map[r][c + 1] == 0 && map[r + 1][c] == 0 && map[nr][nc] == 0) {
		dp[r][c][dir] += dfs(nr, nc, DIA, n);
	}

	return dp[r][c][dir];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}

	fill(&dp[0][0][0], &dp[32][32][2], -1);

	cout << dfs(0, 1, HOR, n) << '\n';

	return 0;
}
