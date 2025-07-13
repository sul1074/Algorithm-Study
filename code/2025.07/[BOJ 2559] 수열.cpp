#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> tempList(n);
	for (int i = 0; i < n; ++i) {
		cin >> tempList[i];
	}

	int currentSum = 0;
	for (int i = 0; i < k; ++i) {
		currentSum += tempList[i];
	}

	int dp = currentSum;
	int left = 1, right = k;

	while (right < n) {
		currentSum = currentSum - tempList[left - 1] + tempList[right];
		dp = max(dp, currentSum);

		++left;
		++right;
	}

	cout << dp << '\n';

	return 0;
}
