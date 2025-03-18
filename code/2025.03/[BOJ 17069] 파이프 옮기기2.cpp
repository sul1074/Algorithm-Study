#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum DirState
{
	HOR, // 수평 상태
	VER, // 수직 상태
	DIA // 대각 상태
};

unsigned long long dp[33][33][3];
int map[33][33];

bool isIn(int r, int c, int size) {
	return r >= 0 && r < size && c >= 0 && c < size;
}

unsigned long long dfs(int r, int c, DirState dir, int size) {
	if (r == size - 1 && c == size - 1) return 1;
	if (dp[r][c][dir] != -1) return dp[r][c][dir];

	dp[r][c][dir] = 0;

	// 수평 이동
	if (dir == HOR || dir == DIA) {
		if (isIn(r, c + 1, size) && map[r][c + 1] == 0) {
			dp[r][c][dir] += dfs(r, c + 1, HOR, size);
		}
	}

	// 수직 이동
	if (dir == VER || dir == DIA) {
		if (isIn(r + 1, c, size) && map[r + 1][c] == 0) {
			dp[r][c][dir] += dfs(r + 1, c, VER, size);
		}
	}

	// 대각선 이동
	if (isIn(r + 1, c + 1, size) && map[r + 1][c + 1] == 0 && map[r][c + 1] == 0 && map[r + 1][c] == 0) {
		dp[r][c][dir] += dfs(r + 1, c + 1, DIA, size);
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
