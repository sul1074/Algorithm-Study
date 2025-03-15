#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int map[100001][3];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> dp(4, vector<int>(3, 0)); // 0~1 = max, 2~3 = min

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 3; ++i) {
		dp[0][i] = map[0][i];
		dp[2][i] = map[0][i];
	}

	for (int i = 1; i < n; ++i) {
		dp[1][0] = map[i][0] + max(dp[0][0], dp[0][1]);
		dp[1][1] = map[i][1] + max(max(dp[0][0], dp[0][1]), dp[0][2]);
		dp[1][2] = map[i][2] + max(dp[0][1], dp[0][2]);

		dp[3][0] = map[i][0] + min(dp[2][0], dp[2][1]);
		dp[3][1] = map[i][1] + min(min(dp[2][0], dp[2][1]), dp[2][2]);
		dp[3][2] = map[i][2] + min(dp[2][1], dp[2][2]);

		// 이전 단계 dp 동기화
		for (int j = 0; j < 3; ++j) {
			dp[0][j] = dp[1][j];
			dp[2][j] = dp[3][j];
		}
	}

	int maxElement = *max_element(dp[1].begin(), dp[1].end());
	int miElement = *min_element(dp[3].begin(), dp[3].end());

	if (n == 1) {
		maxElement = *max_element(dp[0].begin(), dp[0].end());
		miElement = *min_element(dp[0].begin(), dp[0].end());
	}

	cout << maxElement << ' ' << miElement << '\n';

	return 0;
}

/*
 * max = 13 18 9
 * min = 9 14 6
**/
