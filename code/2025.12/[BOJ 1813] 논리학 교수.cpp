#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	unordered_map<int, int> um;
	for (int i = 0; i < n; ++i) {
		int input;
		cin >> input;

		um[input]++;
;	}

	int ans = -1;
	for (const auto& p : um) {
		if (p.first == p.second) ans = max(ans, p.first);
	}

	if (!um.count(0) && ans == -1) ans = 0;

	cout << ans << '\n';

	return 0;
}
