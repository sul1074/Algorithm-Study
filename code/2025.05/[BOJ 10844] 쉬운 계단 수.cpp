#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MOD 1000000000

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	vector<vector<int>> dp(n + 1, vector<int>(10));
	dp[1][0] = 0;
	for (int i = 1; i < 10; ++i) 
		dp[1][i] = 1;

	for (int i = 2; i <= n; ++i) {
		dp[i][0] = dp[i - 1][1];
		for (int j = 1; j < 9; ++j) 
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
		dp[i][9] = dp[i - 1][8];
	}

	int sum = 0;
	for (int i = 0; i < 10; ++i) {
		sum += dp[n][i];
		sum %= MOD;
	}

	cout << sum << '\n';

	return 0;
}
