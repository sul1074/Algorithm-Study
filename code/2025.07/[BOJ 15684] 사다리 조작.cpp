#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool rowLine[31][10] = { false };
int n, m, h;
int ans = 4;

int startLadder(int depth, int curr) {
	if (depth == h + 1) return curr;

	if (curr > 1 && rowLine[depth][curr - 1]) --curr;
	else if (curr < n && rowLine[depth][curr]) ++curr;

	return startLadder(depth + 1, curr);
}

bool isValid() {
	bool rst = true;

	for (int i = 1; i <= n; ++i) {
		if (startLadder(1, i) != i) {
			rst = false;
			break;
		}
	}

	return rst;
}

void backtracking(int depth, int row) {
	if (depth >= ans) return;
	if (isValid()) {
		ans = depth;
		return;
	}

	for (int i = row; i <= h; ++i) {
		for (int j = 1; j < n; ++j) {
			if (rowLine[i][j] || rowLine[i][j - 1] 
				|| rowLine[i][j + 1]) continue;

			rowLine[i][j] = true;
			backtracking(depth + 1, i);
			rowLine[i][j] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> h;

	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		rowLine[a][b] = true;
	}

	backtracking(0, 1);

	if (ans >= 4) cout << -1 << '\n';
	else cout << ans << '\n';

	return 0;
}
