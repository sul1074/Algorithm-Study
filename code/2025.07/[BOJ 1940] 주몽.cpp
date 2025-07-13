#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> materialNum(n);
	for (int i = 0; i < n; ++i) {
		cin >> materialNum[i];
	}

	sort(materialNum.begin(), materialNum.end());

	int ans = 0, left = 0, right = n - 1;

	while (left < right) {
		int sum = materialNum[left] + materialNum[right];

		if (sum == m) {
			++left;
			--right;
			++ans;
		}
		else if (sum < m) {
			++left;
		}
		else {
			--right;
		}
	}

	cout << ans << '\n';

	return 0;
}
