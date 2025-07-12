#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> price(n);
	for (int i = 0; i < n; ++i) {
		cin >> price[i];
	}

	vector<int> dp(k + 1, 0);
	dp[0] = 1;

	for (auto p : price) {
		for (int i = p; i <= k; ++i) {
			dp[i] += dp[i - p];
		}
	}

	cout << dp[k] << '\n';

	return 0;
}
