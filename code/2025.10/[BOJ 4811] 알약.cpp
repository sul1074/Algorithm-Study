#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INIT -1
#define END 0

typedef long long ll;

ll sol(int n) {
	ll dp[31][31] = { 0 };
	for (int i = 0; i <= n; ++i) {
		dp[0][i] = 1;
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (j > 0) dp[i][j] = dp[i - 1][j + 1] + dp[i][j - 1];
			else dp[i][j] = dp[i - 1][j + 1];
		}
	}

	return dp[n][0];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while (1) {
		cin >> n;
		if (n == END) break;
		cout << sol(n) << '\n';
	}

	return 0;
}
