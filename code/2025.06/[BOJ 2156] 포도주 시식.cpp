#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> wine(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> wine[i];
	}

	vector<int> dp(wine);
	dp[2] += wine[1];

	for (int i = 3; i <= n; ++i) {
		dp[i] = max(dp[i - 3] + wine[i - 1] + wine[i], dp[i - 2] + wine[i]);
		dp[i] = max(dp[i - 1], dp[i]);
	}

	cout << dp[n] << '\n';

	return 0;
}
