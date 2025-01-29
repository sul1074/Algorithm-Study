#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::queue;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

bool isIn(const pair<int, int>&, const pair<int, int>&);
int bfs(const pair<int, int>&, const pair<int, int>&, vector<vector<int>>&);

int main(void) {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n, k;
	cin >> m >> n >> k;

	vector<vector<int>> area(m, vector<int>(n, 0));
	vector<int> areaList;
	int areaNum = 0;

	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		// x가 열이고, y가 행을 나타냄
		for (int row = y1; row < y2; ++row) {
			for (int col = x1; col < x2; ++col) {
				area[row][col] = 1; // 직사각형 영역 표시
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			// 직사각형 영역 이거나 방문한 노드면 처리 X
			if (area[i][j] > 0) continue;

			areaList.push_back(bfs({ m, n }, { i, j }, area));
			areaNum++;
		}
	}

	std::sort(areaList.begin(), areaList.end());

	cout << areaNum << '\n';
	for (auto areaSize : areaList) {
		cout << areaSize << ' ';
	}
	cout << '\n';

	return 0;
}

bool isIn(const pair<int, int>& boundary, const pair<int, int>& pos) {
	return (pos.first >= 0 && pos.first < boundary.first) && (pos.second >= 0 && pos.second < boundary.second);
}

int bfs(const pair<int, int>& boundary, const pair<int, int>& start, vector<vector<int>>& area) {
	int areaSize = 1; // start 노드에 대한 넓이 처리
	queue<pair<int, int>> q;

	q.push(start);
	area[start.first][start.second] = 2; // start 노드 방문 처리

	while (!q.empty()) {
		pair<int, int> curr = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curr.first + dx[i];
			int nextY = curr.second + dy[i];
			pair<int, int> next = { nextX, nextY };

			// 다음에 방문할 노드가 범위 밖이거나 이미 방문했으면 처리 X
			if (!isIn(boundary, next) || area[next.first][next.second] > 0) continue;

			q.push(next);
			area[next.first][next.second] = 2;
			areaSize++;
		}
	}

	return areaSize;
}