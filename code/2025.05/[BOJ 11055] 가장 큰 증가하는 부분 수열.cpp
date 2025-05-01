#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	vector<int> nList(n);
	for (int i = 0; i < n; ++i) cin >> nList[i];
	vector<int> dp(nList.begin(), nList.end());

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (nList[i] > nList[j]) {
				dp[i] = max(dp[i], dp[j] + nList[i]);
			}
		}
	}

	cout << *max_element(dp.begin(), dp.end()) << '\n';

	return 0;
}
