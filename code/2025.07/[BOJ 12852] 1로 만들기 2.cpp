#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	vector<vector<int>> dp(n + 1, vector<int>());

	if (n >= 2) {
		dp[2].push_back(2);
		dp[2].push_back(1);
	}

	if (n >= 3) {
		dp[3].push_back(3);
		dp[3].push_back(1);
	}

	for (int i = 4; i <= n; ++i) {
		dp[i].push_back(i);

		if (i % 3 == 0 && i % 2 == 0) {
			if (dp[int(i / 3)].size() < dp[int(i / 2)].size()) {
				for (auto num : dp[int(i / 3)]) {
					dp[i].push_back(num);
				}

				continue;
			}
			else {
				for (auto num : dp[int(i / 2)]) {
					dp[i].push_back(num);
				}

				continue;
			}
		}
		else if (i % 3 == 0) {
			if (dp[int(i / 3)].size() < dp[i - 1].size()) {
				for (auto num : dp[int(i / 3)]) {
					dp[i].push_back(num);
				}

				continue;
			}
		}
		else if (i % 2 == 0) {
			if (dp[int(i / 2)].size() < dp[i - 1].size()) {
				for (auto num : dp[int(i / 2)]) {
					dp[i].push_back(num);
				}

				continue;
			}
		}

		for (auto num : dp[i - 1]) {
			dp[i].push_back(num);
		}
	}

	if (n == 1) {
		cout << 0 << '\n';
		cout << 1;
	}

	else {
		cout << dp[n].size() - 1 << '\n';
		for (auto num : dp[n]) {
			cout << num << ' ';
		}
	}

	return 0;
}

/*
* 2, 1
* 3, 1
* 4, 2, 1
* 5, 4, 2, 1
* 6, 2, 1
* 7, 6, 2, 1
* 8, 4, 2, 1
* 9, 3, 1
* 10, 9, 3, 1
*/
