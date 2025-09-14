#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<double> numList(n);
	for (int i = 0; i < n; ++i) {
		cin >> numList[i];
	}

	vector<double> dp(n, 0);
	dp[0] = numList[0];

	double ans = dp[0];
	for (int i = 1; i < n; ++i) {
		dp[i] = max(numList[i], dp[i - 1] * numList[i]);
		ans = max(ans, dp[i]);
	}

	cout << fixed;
	cout.precision(3);
	cout << ans << '\n';

	return 0;
}
