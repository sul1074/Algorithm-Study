#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numFreq[100001] = { 0 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> nList(n);
	for (int i = 0; i < n; ++i) {
		cin >> nList[i];
	}

	int maxLen = 0, left = 0, right = 0;
	while (right < n) {
		numFreq[nList[right]] += 1;

		while (numFreq[nList[right]] > k) {
			numFreq[nList[left]] -= 1;
			++left;
		}

		++right;

		maxLen = max(right - left, maxLen);
	}

	cout << maxLen << '\n';

	return 0;
}
