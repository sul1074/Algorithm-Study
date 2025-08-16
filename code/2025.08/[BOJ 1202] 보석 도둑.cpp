#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int n, k;

struct Jewel {
	int m, v;
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	vector<Jewel> jewels(n);
	for (int i = 0; i < n; ++i) {
		cin >> jewels[i].m >> jewels[i].v;
	}
	sort(jewels.begin(), jewels.end(), [](const Jewel& a, const Jewel& b) {
		return a.m < b.m;
	});

	vector<int> bags(k);
	for (int i = 0; i < k; ++i) {
		cin >> bags[i];
	}
	sort(bags.begin(), bags.end());

	priority_queue<int> pq;
	int jewelIdx = 0;
	long long ans = 0;

	for (auto bag : bags) {
		while (jewelIdx < n && jewels[jewelIdx].m <= bag) {
			pq.push(jewels[jewelIdx++].v);
		}

		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans << '\n';

	return 0;
}
