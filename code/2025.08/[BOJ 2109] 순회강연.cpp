#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

struct Lecture {
	int pay;
	int deadline;
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> pq;

	int n;
	cin >> n;

	vector<Lecture> lectures(n);
	for (int i = 0; i < n; ++i) {
		cin >> lectures[i].pay >> lectures[i].deadline;
	}

	sort(lectures.begin(), lectures.end(), [](const Lecture& a, const Lecture& b) {
		return a.deadline < b.deadline;
	});

	for (const auto& lec : lectures) {
		if (lec.deadline > pq.size()) {
			pq.push(lec.pay);
			continue;
		}

		if (lec.pay > pq.top()) {
			pq.pop();
			pq.push(lec.pay);
		}
	}

	int ans = 0;
	while (!pq.empty()) {
		ans += pq.top(); pq.pop();
	}

	cout << ans << '\n';

	return 0;
}
