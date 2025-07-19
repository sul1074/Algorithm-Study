#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Pos {
	int r;
	int c;
};

int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int map[8][8];
Pos dimension;

bool isIn(const Pos& curr) {
	return curr.r >= 0 && curr.r < dimension.r &&
		curr.c >= 0 && curr.c < dimension.c;
}

int bfs(const vector<Pos>& virusList) {
	queue<Pos> q;
	for (auto p : virusList) {
		q.push(p);
	}

	bool visited[8][8] = { false };
	for (auto p : virusList) {
		visited[p.r][p.c] = true;
	}

	int spreadOut = 0;
	while (!q.empty()) {
		Pos curr = q.front(); q.pop();

		for (int i = 0; i < 4; ++i) {
			Pos next = { curr.r + dr[i], curr.c + dc[i] };

			if (isIn(next) && !visited[next.r][next.c]
				&& map[next.r][next.c] == 0) {
				q.push(next);
				visited[next.r][next.c] = true;
				++spreadOut;
			}
		}
	}

	return spreadOut;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> dimension.r >> dimension.c;

	int wallNum = 0;
	vector<Pos> virusList;
	for (int i = 0; i < dimension.r; ++i) {
		for (int j = 0; j < dimension.c; ++j) {
			int input;
			cin >> input;

			if (input == 2) virusList.push_back({ i, j });
			else if (input == 1) ++wallNum;
			map[i][j] = input;
		}
	}

	vector<Pos> posList;
	for (int i = 0; i < dimension.r; ++i) {
		for (int j = 0; j < dimension.c; ++j) {
			posList.push_back({ i, j });
		}
	}

	int ans = 0;
	int sz = posList.size();
	for (int i = 0; i < sz; ++i) {
		for (int j = i + 1; j < sz; ++j) {
			for (int k = j + 1; k < sz; ++k) {
				Pos wall1 = posList[i];
				Pos wall2 = posList[j];
				Pos wall3 = posList[k];

				if (map[wall1.r][wall1.c] == 0 &&
					map[wall2.r][wall2.c] == 0 &&
					map[wall3.r][wall3.c] == 0) {


					map[wall1.r][wall1.c] = 1;
					map[wall2.r][wall2.c] = 1;
					map[wall3.r][wall3.c] = 1;

					int spreadOut = bfs(virusList);

					int rst = dimension.r * dimension.c 
						- (spreadOut + virusList.size() + wallNum + 3);
					ans = max(ans, rst);

					map[wall1.r][wall1.c] = 0;
					map[wall2.r][wall2.c] = 0;
					map[wall3.r][wall3.c] = 0;
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}

/*
* 벽 3개 다 세워야 함
* 0 - 빈 칸
* 1 - 벽
* 2 - 바이러스
* 그냥 n^3으로 모든 벽을 세우는 경우의 수 구해서 bfs돌리면 될듯 -> 64*64*64*64
*/
