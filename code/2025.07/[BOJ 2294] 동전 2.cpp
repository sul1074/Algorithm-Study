#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 21470000

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> price(n);
	for (int i = 0; i < n; ++i) {
		cin >> price[i];
	}

	vector<int> dp(k + 1, MAX);
	for (auto p : price) {
		if (p > k) continue;

		dp[p] = 1;
	}

	for (int i = 1; i <= k; ++i) {
		for (auto p : price) {
			if (i - p <= 0) continue;

			dp[i] = min(dp[i], dp[i - p] + 1);
		}
	}

	if (dp[k] == MAX) cout << -1 << '\n';
	else cout << dp[k] << '\n';

	return 0;
}
