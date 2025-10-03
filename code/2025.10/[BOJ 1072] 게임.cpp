#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int x, y;
	cin >> x >> y;

	int init = (double)y / x * 100, ans = -1;
	int left = 1, right = 1000000000;

	while (left <= right) {
		int mid = (left + right) / 2;
		int temp = (double)(y + mid) / (x + mid) * 100;

		if (temp > init) {
			right = mid - 1;
			ans = mid;
		}
		else {
			left = mid + 1;
		}
	}

	cout << ans << '\n';

	return 0;
}
