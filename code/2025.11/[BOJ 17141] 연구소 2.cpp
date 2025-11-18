#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

struct Pos {
	int r, c;
};

const int dr[4] = { 1, 0, -1, 0 };
const int dc[4] = { 0, 1, 0, -1 };

int n, m;

bool isIn(const Pos& curr) {
	return curr.r >= 0 && curr.r < n && curr.c >= 0 && curr.c < n;
}

bool isEnd(const vector<vector<int>>& visited) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (visited[i][j] < 0) return false;
		}
	}

	return true;
}

void backtracking(
	const vector<Pos>& canPlaceVirusPos, 
	vector<vector<Pos>>& placedVirusPosList,
	vector<Pos>& temp,
	int start) {
	if (temp.size() >= m) {
		placedVirusPosList.push_back(temp);
		return;
	}

	for (int i = start; i < canPlaceVirusPos.size(); ++i) {
		temp.push_back(*(canPlaceVirusPos.begin() + i));
		backtracking(canPlaceVirusPos, placedVirusPosList, temp, i + 1);
		temp.pop_back();
	}
}

int bfs(const vector<vector<int>>& insMap, const vector<Pos>& virus) {
	vector<vector<int>> visited(n, vector<int>(n, -1));
	queue<Pos> q;
	int time = 0;
	bool allSpread = false;

	// 벽은 미리 방문처리
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (insMap[i][j] == 1) visited[i][j] = 0;
		}
	}

	for (const auto& v : virus) {
		q.push(v);
		visited[v.r][v.c] = 0;
	}

	while (!q.empty()) {
		int turn = q.size();
		for (int i = 0; i < turn; ++i) {
			Pos curr = q.front(); q.pop();

			for (int j = 0; j < 4; ++j) {
				Pos next = { curr.r + dr[j], curr.c + dc[j] };

				if (!isIn(next) 
					|| visited[next.r][next.c] >= 0 
					|| insMap[next.r][next.c] == 1) continue;

				q.push(next);
				visited[next.r][next.c] = visited[curr.r][curr.c] + 1;
				time = max(time, visited[next.r][next.c]);
			}
		}

		if (isEnd(visited)) {
			allSpread = true;
			break;
		}
	}

	if (allSpread) return time;
	else return -1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	vector<vector<Pos>> placedVirusPosList;
	vector<Pos> canPlaceVirusPos;
	vector<Pos> temp;
	vector<vector<int>> insMap(n, vector<int>(n));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> insMap[i][j];

			if (insMap[i][j] == 2) canPlaceVirusPos.push_back({ i, j });
		}
	}

	backtracking(canPlaceVirusPos, placedVirusPosList, temp, 0);
	int ans = INT_MAX;

	for (const auto& virusPosList : placedVirusPosList) {
		int rst = bfs(insMap, virusPosList);
		if (rst >= 0) ans = min(ans, rst);
	}

	if (ans == INT_MAX) ans = -1;
	cout << ans << '\n';

	return 0;
}

/*
* 0이 빈 칸
* 1은 벽
* 2는 바이러스를 놓을 수 있는 곳
* 
* 바이러스는 상하좌우 빈 칸으로 번질 수 있음
* 특정 위치에 M개의 바이러스를 놓을 때, 바이러스가
* 모두 퍼지는 데 걸리는 최소 시간
* 
* 최소 시간이 되도록 바이러스를 M개 배치하자
*/
