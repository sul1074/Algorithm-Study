#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	b *= 2;
	c *= 3;

	int ans = 0;
	vector<int> parkInfo(101, 0);

	int s, e;
	for (int i = 0; i < 3; ++i) {
		cin >> s >> e;

		for (int j = s; j < e; ++j) {
			if (parkInfo[j] == 0) parkInfo[j] = a;
			else if (parkInfo[j] == a) parkInfo[j] = b;
			else if (parkInfo[j] == b) parkInfo[j] = c;
		}
	}

	for (auto parkFee : parkInfo) {
		ans += parkFee;
	}

	cout << ans << '\n';

	return 0;
}
