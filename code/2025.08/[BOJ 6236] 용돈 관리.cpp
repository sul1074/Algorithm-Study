#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int left = 0, right = 0;
	vector<int> money(n);
	for (int i = 0; i < n; ++i) {
		cin >> money[i];
		left = max(left, money[i]);
		right += money[i];
	}

	int ans = INT_MAX;
	while (left <= right) {
		int mid = (left + right + 1) / 2; // ceil과 같음
		int cnt = 1, curr = mid;

		for (const auto m : money) {
			curr -= m;
			if (curr < 0) {
				curr = mid - m;
				++cnt;
			}
		}

		if (cnt > m) left = mid + 1;
		else {
			ans = min(ans, mid);
			right = mid - 1;
		}
	}

	cout << ans << '\n';
	
	return 0;
}
