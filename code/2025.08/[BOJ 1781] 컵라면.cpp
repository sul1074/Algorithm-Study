#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

struct Homework {
	int deadline;
	int reward;
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;

	vector<Homework> homeworks(n);
	for (int i = 0; i < n; ++i) {
		cin >> homeworks[i].deadline >> homeworks[i].reward;
	}
	sort(homeworks.begin(), homeworks.end(), [](const Homework& a, const Homework& b) {
		return a.deadline < b.deadline;
	});


	for (const auto& homework : homeworks) {
		if (homework.deadline > pq.size()) {
			pq.push(homework.reward);
			continue;
		}

		if (homework.reward > pq.top()) {
			pq.pop();
			pq.push(homework.reward);
		}
	}

	int ans = 0;
	while (!pq.empty()) {
		ans += pq.top(); pq.pop();
	}

	cout << ans << '\n';

	return 0;
}
