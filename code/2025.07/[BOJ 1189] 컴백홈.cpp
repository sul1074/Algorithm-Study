#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pos {
	int r, c;

	bool operator==(const Pos& other) {
		return other.r == r && other.c == c;
	}
};

const int dr[4] = { 1, 0, -1, 0 };
const int dc[4] = { 0, 1, 0, -1 };

int r, c, k;
char map[5][5];

Pos start, goal;
int ans = 0;

bool isIn(const Pos& p) {
	return p.r >= 0 && p.r < r && p.c >= 0 && p.c < c;
}

void dfs(Pos curr, int depth) {
	if (curr == goal) {
		if (depth == k) ++ans;
		return;
	}

	for (int i = 0; i < 4; ++i) {
		Pos next = { curr.r + dr[i], curr.c + dc[i] };

		if (!isIn(next) || map[next.r][next.c] == 'T') continue;

		map[next.r][next.c] = 'T';
		dfs(next, depth + 1);
		map[next.r][next.c] = '.';
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c >> k;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> map[i][j];
		}
	}

	start = { r - 1, 0 };
	goal = { 0, c - 1 };

	map[start.r][start.c] = 'T';
	dfs(start, 1);
	cout << ans << '\n';

	return 0;
}