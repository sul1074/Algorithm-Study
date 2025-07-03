#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long sol(int n, const vector<unsigned long>& road, const vector<unsigned long>& gas) {
	unsigned long ans = 0;
	unsigned long minPrice = *min_element(gas.begin(), gas.end() - 1);
	unsigned long greedy = gas[0];

	for (int i = 0; i < n - 1; ++i) {
		greedy = min(greedy, gas[i]);

		if (greedy == minPrice) {
			for (int j = i; j < n - 1; ++j) {
				ans += greedy * road[j];
			}

			return ans;
		}

		ans += greedy * road[i];
	}

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<unsigned long> road(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		cin >> road[i];
	}

	vector<unsigned long> gas(n);
	for (int i = 0; i < n; ++i) {
		cin >> gas[i];
	}

	cout << sol(n, road, gas) << '\n';

	return 0;
}
