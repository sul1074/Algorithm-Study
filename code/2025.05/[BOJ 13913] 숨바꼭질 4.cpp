#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(int n, int k, vector<int>& prev) {
	queue<int> q;
	q.push(n);

	int time = 0;
	while (!q.empty()) {
		int turn = q.size();

		for (int i = 0; i < turn; ++i) {
			int curr = q.front(); q.pop();

			if (curr == k) return time;

			int nexts[3] = { curr * 2, curr - 1, curr + 1 };

			for (int i = 0; i < 3; ++i) {
				if (nexts[i] < 0 || nexts[i] > 100000 || prev[nexts[i]] > -1) continue;

				q.push(nexts[i]);
				prev[nexts[i]] = curr;
			}
		}

		++time;
	}

	return time;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int > prev(100001, -1);
	vector<int> path;

	int n, k;
	cin >> n >> k;
	
	int time = bfs(n, k, prev);
	int prevPos = k;

	path.push_back(k);
	while (prevPos != n) {
		path.push_back(prev[prevPos]);
		prevPos = prev[prevPos];
	}
	reverse(path.begin(), path.end());

	cout << time << '\n';
	for (int p : path) {
		cout << p << ' ';
	}

	return 0;
}
