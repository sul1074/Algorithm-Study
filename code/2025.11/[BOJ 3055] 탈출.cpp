#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Pos {
	int r, c;

	bool equal(const Pos& other) {
		return other.r == r && other.c == c;
	}
};

const int dr[4] = { 1, 0, -1, 0 };
const int dc[4] = { 0, 1, 0, -1 };
int R, C;

bool isIn(const Pos& curr) {
	return curr.r >= 0 && curr.r < R && curr.c >= 0 && curr.c < C;
}

int bfs(vector<vector<char>>& twMap, queue<Pos>& waterPosList,
	const Pos& start, const Pos& dest) {

	queue<Pos> q;
	vector<vector<bool>> visited(R, vector<bool>(C, false));
	int time = 0;

	q.push(start);
	visited[start.r][start.c] = true;

	while (!q.empty()) {
		// 물 먼저 이동
		int waterSize = waterPosList.size();
		for (int i = 0; i < waterSize; ++i) {
			Pos waterPos = waterPosList.front(); waterPosList.pop();

			for (int i = 0; i < 4; ++i) {
				Pos next = { waterPos.r + dr[i], waterPos.c + dc[i] };

				if (!isIn(next) || twMap[next.r][next.c] != '.') continue;

				twMap[next.r][next.c] = '*';
				waterPosList.push(next);
			}
		}

		// 고슴도치 이동
		int turnTime = q.size();
		for (int i = 0; i < turnTime; ++i) {
			Pos curr = q.front(); q.pop();
			if (curr.equal(dest)) return time;

			for (int i = 0; i < 4; ++i) {
				Pos next = { curr.r + dr[i], curr.c + dc[i] };

				if (!isIn(next)
					|| visited[next.r][next.c]
					|| twMap[next.r][next.c] == '*'
					|| twMap[next.r][next.c] == 'X') continue;

				q.push(next);
				visited[next.r][next.c] = true;
			}
		}

		++time;
	}

	return -1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;

	Pos start, dest;
	vector<vector<char>> twMap(R, vector<char>(C));
	queue<Pos> waterPosList;

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			char temp;
			cin >> temp;
			twMap[i][j] = temp;

			if (temp == '*') waterPosList.push({ i, j });
			else if (temp == 'S') start = { i, j };
			else if (temp == 'D') dest = { i, j };
		}
	}
	twMap[start.r][start.c] = '.';
	
	int rst = bfs(twMap, waterPosList, start, dest);
	if (rst > 0) cout << rst << '\n';
	else cout << "KAKTUS\n";

	return 0;
}

/*
* 물은 돌이랑 비버굴 이동 불가
* 물은 인접한 곳으로 이동해서 차오름
* 물이 먼저 차오르기 때문에, 물이 차오를 예정인 칸은 이동 불가능함
* 
* 돌은 X, 물은 *
*/
