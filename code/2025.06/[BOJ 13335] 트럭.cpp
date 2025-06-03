#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, w, l;
	cin >> n >> w >> l;

	vector<int> trucks(n);
	for (int i = 0; i < n; ++i) {
		cin >> trucks[i];
	}

	int accumWeight = trucks[0], idx = 1, time = 1;
	vector<pair<int, int>> q;
	q.push_back({ trucks[0], w });


	while (!q.empty()) {
		++time;

		for (auto& t : q) --t.second;

		if (q.front().second == 0) {
			accumWeight -= q.front().first;
			q.erase(q.begin());
		}

		for (int i = idx; i < n; ++i) {
			int nextTruckWeight = trucks[i];

			if (accumWeight + nextTruckWeight > l || q.size() >= w) break;
			
			q.push_back({ nextTruckWeight, w });
			accumWeight += nextTruckWeight;
			++idx;	

			break;
		}
	}

	cout << time;

	return 0;
}
