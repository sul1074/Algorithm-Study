#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; ++i) cin >> nums[i];
	vector<int> dp(nums.begin(), nums.end());

	for (int i = 1; i < n; ++i) {
		dp[i] = max(dp[i], dp[i - 1] + nums[i]);
	}

	cout << *max_element(dp.begin(), dp.end()) << '\n';

	return 0;
}
