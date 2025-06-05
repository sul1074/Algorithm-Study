#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pos;

int dist(const Pos& p1, const Pos& p2) {
	return (abs(p1.first - p2.first) + abs(p1.second - p2.second));
}

void bfs(const vector<Pos>& map) {
	vector<Pos> visited;
	Pos festivalPos = map.back();
	queue<Pos> q;
	q.push(map.front()); // 상근이 집
	visited.push_back(map.front());

	while (!q.empty()) {
		Pos curr = q.front(); q.pop();

		if (curr.first == festivalPos.first && curr.second == festivalPos.second) {
			cout << "happy" << '\n';
			return;
		}

		for (auto next : map) {
			if (find(visited.begin(), visited.end(), next) != visited.end()
				|| dist(curr, next) > 1000) continue;

			q.push(next);
			visited.push_back(next);
		}
	}

	cout << "sad" << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;

		vector<Pos> map;

		for (int j = 0; j < n + 2; ++j) {
			int x, y;
			cin >> x >> y;

			map.push_back({ x, y });
		}

		bfs(map);
	}

	return 0;
}
