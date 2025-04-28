#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pos;

int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool isIn(pos p) {
	return p.first >= 0 && p.first < n && p.second >= 0 && p.second < m;
}

int bfs(vector<vector<int>>& paper, pos p) {
	int cnt = 1;
	queue<pos> q;
	q.push(p);
	paper[p.first][p.second] = 0;

	while (!q.empty()) {
		pos curr = q.front(); 
		q.pop();

		for (int i = 0; i < 4; ++i) {
			pos next = { curr.first + dx[i], curr.second + dy[i] };
			if (!isIn(next) || paper[next.first][next.second] == 0) continue;

			paper[next.first][next.second] = 0;
			q.push(next);
			++cnt;
		}
	}

	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<int> ans;
	cin >> n >> m;

	vector<vector<int>> paper(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> paper[i][j];
		}
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (paper[i][j] == 0) continue;
			ans.push_back(bfs(paper, { i, j }));
		}
	}

	if (ans.empty()) {
		cout << 0 << '\n';
		cout << 0 << '\n';
	}
	else {
		cout << ans.size() << '\n';
		cout << *max_element(ans.begin(), ans.end()) << '\n';
	}
	
	return 0;
}
