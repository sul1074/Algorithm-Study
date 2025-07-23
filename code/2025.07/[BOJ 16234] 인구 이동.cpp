#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std; 

struct Pos {
	int r;
	int c;

	bool operator==(const Pos& p) const {
		return p.r == r && p.c == c;
	}
};

int n, l, r;
int map[50][50];

const int dr[4] = { 1, 0, -1, 0 };
const int dc[4] = { 0, 1, 0, -1 };

bool isIn(const Pos& curr) {
	return curr.r >= 0 && curr.r < n && curr.c >= 0 && curr.c < n;
}

bool canUnion(const Pos& c1, const Pos& c2) {
	int diff = abs(map[c1.r][c1.c] - map[c2.r][c2.c]);

	return diff >= l && diff <= r;
}

void bfs(const Pos& start, vector<vector<bool>>& visited, vector<vector<Pos>>& unionList) {
	queue<Pos> q;
	vector<Pos> u;

	q.push(start);
	u.push_back(start);
	visited[start.r][start.c] = true;

	while (!q.empty()) {
		Pos curr = q.front(); q.pop();

		for (int i = 0; i < 4; ++i) {
			Pos next = { curr.r + dr[i], curr.c + dc[i] };
			
			if (!isIn(next) || visited[next.r][next.c]) continue;

			if (canUnion(curr, next)) {
				u.push_back(next);
				q.push(next);
				visited[next.r][next.c] = true;
			}
		}
	}

	if (u.size() > 1) unionList.push_back(u);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	int ans = 0;
	
	while (1) {
		vector<vector<bool>> visited(n, vector<bool>(n, false));
		vector<vector<Pos>> unionList;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (visited[i][j]) continue;

				bfs({ i, j }, visited, unionList);
			}
		}

		if (unionList.empty()) break;

		for (auto s : unionList) {
			int num = s.size();
			int sum = 0;

			for (auto p : s) sum += map[p.r][p.c];

			int adjustedPopul = sum / num;

			for (auto p : s) map[p.r][p.c] = adjustedPopul;
		}

		++ans;
	}

	cout << ans << '\n';

	return 0;
}
