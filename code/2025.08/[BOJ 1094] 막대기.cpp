#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int x;

int backtracking(int depth, int curr, int idx) {
	if (curr == x) return depth;

	int ans = 21470000;
	for (int i = idx; i < 8; ++i) {
		ans = min(ans, backtracking(depth + 1, curr + (1 << i), i + 1));
	}

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x;
	cout << backtracking(0, 0, 0) << '\n';

	return 0;
}
