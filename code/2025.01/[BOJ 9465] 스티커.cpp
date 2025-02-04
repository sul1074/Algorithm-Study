#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;

int main(void) {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for (int time = 0; time < t; time++) {
		int n;
		cin >> n;

		vector<vector<int>> dp(2, vector<int>(n, 0));
		vector<vector<int>> sticker(2, vector<int>(n, 0));
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> sticker[i][j];
			}
		}

		dp[0][0] = sticker[0][0];
		dp[1][0] = sticker[1][0];

		if (n > 1) {
			dp[0][1] = dp[1][0] + sticker[0][1];
			dp[1][1] = dp[0][0] + sticker[1][1];
		}

		for (int i = 2; i < n; i++) {
			dp[0][i] = sticker[0][i] + std::max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = sticker[1][i] + std::max(dp[0][i - 1], dp[0][i - 2]);
		}

		cout << std::max(dp[0][n - 1], dp[1][n - 1]) << '\n';

	}

	return 0;
}