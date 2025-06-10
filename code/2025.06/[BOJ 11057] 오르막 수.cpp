#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> dp(n + 1, vector<int>(10, 0));
	for (int j = 0; j <= 9; ++j) {
		dp[1][j] = 1;
	}

	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j <= 9; ++j) {
			for (int k = j; k <= 9; ++k) {
				dp[i][j] += dp[i - 1][k] % 10007;
			}
		}
	}

	int ans = 0;
	for (auto num : dp[n]) {
		ans += num % 10007;
	}

	cout << ans % 10007 << '\n';

	return 0;
}
