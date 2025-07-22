#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Pos {
	int r;
	int c;
};

const int dr[4] = { 0, 0, 1, -1 };
const int dc[4] = { 1, -1, 0, 0 };

char classroom[300][300];
int n, m;
Pos junanPos, friendPos;

bool isIn(Pos curr) {
	return curr.r >= 0 && curr.r < n && curr.c >= 0 && curr.c < m;
}

int bfs() {
	queue<Pos> wave;
	queue<Pos> process;

	Pos adjustedJunanPos = { junanPos.r - 1, junanPos.c - 1 };
	wave.push(adjustedJunanPos);

	int ans = 0;

	vector<vector<bool>> visited(n, vector<bool>(m, false));

	while (!wave.empty()) {
		int waveNum = wave.size();
		++ans;
		
		for (int i = 0; i < waveNum; ++i) {
			Pos center = wave.front(); wave.pop();
			visited[center.r][center.c] = true;

			for (int i = 0; i < 4; ++i) {
				Pos waveSpread = { center.r + dr[i], center.c + dc[i],};

				if (!isIn(waveSpread) || visited[waveSpread.r][waveSpread.c]) continue;

				if (classroom[waveSpread.r][waveSpread.c] == '0') process.push(waveSpread);
				else if (classroom[waveSpread.r][waveSpread.c] == '1') {
					wave.push(waveSpread);
					classroom[waveSpread.r][waveSpread.c] = '0';
				}
				else if (classroom[waveSpread.r][waveSpread.c] == '#') return ans;

				visited[waveSpread.r][waveSpread.c] = true;
			}
		}

		// 파동 전이 시작
		while (!process.empty()) {
			Pos curr = process.front(); process.pop();
			visited[curr.r][curr.c] = true;

			for (int i = 0; i < 4; ++i) {
				Pos waveSpread = { curr.r + dr[i], curr.c + dc[i], };

				if (!isIn(waveSpread) || visited[waveSpread.r][waveSpread.c]) continue;

				if (classroom[waveSpread.r][waveSpread.c] == '0') process.push(waveSpread);
				else if (classroom[waveSpread.r][waveSpread.c] == '1') {
					wave.push(waveSpread);
					classroom[waveSpread.r][waveSpread.c] = '0';
				}
				else if (classroom[waveSpread.r][waveSpread.c] == '#') return ans;

				visited[waveSpread.r][waveSpread.c] = true;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	cin >> junanPos.r >> junanPos.c >> friendPos.r >> friendPos.c;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char input;
			cin >> classroom[i][j];
		}
	}

	cout << bfs() << '\n';

	return 0;
}
