#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 999999

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, r, ans = 0;
	cin >> n >> m >> r;

	vector<int> itemNums(n + 1);
	vector<vector<int>> field(n + 1, vector<int>(n + 1, INF));

	for (int i = 1; i <= n; ++i) {
		cin >> itemNums[i];
	}

	for (int i = 0; i < r; ++i) {
		int a, b, l;
		cin >> a >> b >> l;

		field[a][b] = l;
		field[b][a] = l;
	}
	for (int i = 1; i <= n; ++i) {
		field[i][i] = 0;
	}

	// apply floyd
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				field[i][j] = min(field[i][j], field[i][k] + field[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		int sum = 0;

		for (int j = 1; j <= n; ++j) {
			if (field[i][j] > m) continue;
			
			sum += itemNums[j];
		}

		ans = max(ans, sum);
	}

	cout << ans << '\n';

	return 0;
}
