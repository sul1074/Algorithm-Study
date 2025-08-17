#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pos {
	int r, c;
};

struct Dust {
	Pos p;
	int before, after;
};

int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };

Pos roomSize;
int map[51][51];
int airRow[2] = { -1 }; // 0이 윗쪽, 1이 아래쪽 행

bool isIn(const Pos& p) {
	return p.r >= 0 && p.r < roomSize.r
		&& p.c >= 0 && p.c < roomSize.c;
}

void spread(const Pos& p, vector<vector<int>>& spreadedDust) {
	int spreadNum = map[p.r][p.c] / 5;

	for (int i = 0; i < 4; ++i) {
		Pos next = { p.r + dr[i], p.c + dc[i] };

		if (isIn(next) && map[next.r][next.c] != -1) {
			spreadedDust[next.r][next.c] += spreadNum;
			map[p.r][p.c] -= spreadNum;
		}
	}
}

void processAirCon() {
	Pos airCeil = { airRow[0], 0 }, airBottom = { airRow[1], 0 };

	int prev = map[airCeil.r][1];
	map[airCeil.r][1] = 0;
	// 오른쪽
	for (int col = 2; col < roomSize.c; ++col) {
		int temp = map[airCeil.r][col];
		map[airCeil.r][col] = prev;
		prev = temp;
	}
	// 윗쪽
	for (int row = airCeil.r - 1; row >= 0; --row) {
		int temp = map[row][roomSize.c - 1];
		map[row][roomSize.c - 1] = prev;
		prev = temp;
	}
	// 왼쪽
	for (int col = roomSize.c - 2; col >= 0; --col) {
		int temp = map[0][col];
		map[0][col] = prev;
		prev = temp;
	}
	// 아랫쪽
	for (int row = 1; row < airCeil.r; ++row) {
		int temp = map[row][0];
		map[row][0] = prev;
		prev = temp;
	}

	prev = map[airBottom.r][1];
	map[airBottom.r][1] = 0;
	// 오른쪽
	for (int col = 2; col < roomSize.c; ++col) {
		int temp = map[airBottom.r][col];
		map[airBottom.r][col] = prev;
		prev = temp;
	}
	// 아랫쪽
	for (int row = airBottom.r + 1; row < roomSize.r; ++row) {
		int temp = map[row][roomSize.c - 1];
		map[row][roomSize.c - 1] = prev;
		prev = temp;
	}
	// 왼쪽
	for (int col = roomSize.c - 2; col >= 0; --col) {
		int temp = map[roomSize.r - 1][col];
		map[roomSize.r - 1][col] = prev;
		prev = temp;
	}
	// 윗쪽
	for (int row = roomSize.r - 2; row > airBottom.r; --row) {
		int temp = map[row][0];
		map[row][0] = prev;
		prev = temp;
	}
}

void process() {
	vector<vector<int>> spreadedDust(roomSize.r, vector<int>(roomSize.c, 0));

	for (int i = 0; i < roomSize.r; ++i) {
		for (int j = 0; j < roomSize.c; ++j) {
			if (map[i][j] > 0) spread({ i, j }, spreadedDust);
		}
	}
	for (int i = 0; i < roomSize.r; ++i) {
		for (int j = 0; j < roomSize.c; ++j) {
			map[i][j] += spreadedDust[i][j];
		}
	}

	processAirCon();
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, input;
	cin >> roomSize.r >> roomSize.c >> t;
	for (int i = 0; i < roomSize.r; ++i) {
		for (int j = 0; j < roomSize.c; ++j) {
			cin >> input;
			map[i][j] = input;

			if (input == -1) {
				if (airRow[0] < 0) airRow[0] = i;
				else airRow[1] = i;
			}
		}
	}

	for (int i = 0; i < t; ++i) {
		process();
	}
	
	int cnt = 0;
	for (int i = 0; i < roomSize.r; ++i) {
		for (int j = 0; j < roomSize.c; ++j) {
			if (map[i][j] > 0) cnt += map[i][j];
		}
	}

	cout << cnt << '\n';

	return 0;
}
