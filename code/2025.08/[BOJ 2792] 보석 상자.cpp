#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int total = 0, maxVal = -1;
	vector<int> color(m);
	for (int i = 0; i < m; ++i) {
		cin >> color[i];
		total += color[i];
		maxVal = max(maxVal, color[i]);
	}

	int ans = 214700000;
	int left = (total + n - 1) / n, right = maxVal;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;

		for (auto num : color) {
			cnt += (num + mid - 1) / mid;
		}

		if (cnt > n) {
			left = mid + 1;
		}
		else {
			ans = min(ans, mid);
			right = mid - 1;
		}
	}

	cout << ans << '\n';

	return 0;
}
