#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> cardPrices(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> cardPrices[i];
	}

	vector<int> dp(cardPrices);

	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			dp[i] = max(dp[i], dp[j] + dp[i - j]);
		}
	}

	cout << dp[n] << '\n';

	return 0;
}
