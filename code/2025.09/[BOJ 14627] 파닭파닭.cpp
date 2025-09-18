#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int s, c;
	cin >> s >> c;

	int left = 1;
	int right = -1;

	vector<int> greenOnions(s);
	long long ans = 0;
	for (int i = 0; i < s; ++i) {
		cin >> greenOnions[i];
		ans += greenOnions[i];
		if (right < greenOnions[i]) right = greenOnions[i];
	}

	long long optOnion = -1;
	while (left <= right) {
		long long mid = (left + right + 1) / 2;
		long long cnt = 0;

		for (const auto& greenOnion : greenOnions) {
			cnt += greenOnion / mid;
		}

		if (cnt < c) {
			right = mid - 1;
		}
		else if (cnt >= c) {
			left = mid + 1;
			optOnion = max(optOnion, mid);
		}
	}

	cout << ans - optOnion * c << '\n';

	return 0;
}
