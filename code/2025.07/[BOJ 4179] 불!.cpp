#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
	int r;
	int c;
};

int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };

bool isIn(Point size, Point start) {
	return start.r >= 0 && start.c >= 0 
		&& start.r < size.r && start.c < size.c;
}

bool isEscaped(Point size, Point curr) {
	return curr.r == 0 || curr.c == 0
		|| curr.r == size.r - 1 || curr.c == size.c - 1;
}

int bfs(vector<vector<char>>& building, queue<Point>& fireQ, 
	vector<vector<bool>>& fireVisited, Point size, Point start) {

	queue<Point> personQ;
	vector<vector<bool>> personVisited(size.r, vector<bool>(size.c, false));

	personQ.push(start);
	personVisited[start.r][start.c] = true;

	int cnt = 0;

	while (!personQ.empty()) {
		int fireTurn = fireQ.size();

		for (int i = 0; i < fireTurn; ++i) {
			Point curr = fireQ.front(); fireQ.pop();

			for (int i = 0; i < 4; ++i) {
				Point diffusion = { curr.r + dr[i], curr.c + dc[i] };

				if (isIn(size, diffusion) && building[diffusion.r][diffusion.c] == '.'
					&& !fireVisited[diffusion.r][diffusion.c]) {

					building[diffusion.r][diffusion.c] = 'F';
					fireVisited[diffusion.r][diffusion.c] = true;
					fireQ.push(diffusion);
				}
			}
		}

		int personTurn = personQ.size();

		for (int i = 0; i < personTurn; ++i) {
			Point curr = personQ.front(); personQ.pop();

			if (isEscaped(size, curr)) return cnt;

			for (int i = 0; i < 4; ++i) {
				Point next = { curr.r + dr[i], curr.c + dc[i] };

				if (isIn(size, next) && building[next.r][next.c] == '.'
					&& !personVisited[next.r][next.c]) {

					personQ.push(next);
					personVisited[next.r][next.c] = true;
				}
			}
		}

		cnt++;
	}

	return -1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Point size;
	cin >> size.r >> size.c;

	Point start;
	queue<Point> fireQ;
	vector<vector<bool>> fireVisited(size.r, vector<bool>(size.c, false));

	vector<vector<char>> building(size.r, vector<char>(size.c));
	for (int i = 0; i < size.r; ++i) {
		for (int j = 0; j < size.c; ++j) {
			char input;
			cin >> input;
			building[i][j] = input;


			if (input == 'J') {
				start.r = i;
				start.c = j;
				building[i][j] = '.';
			}
			else if (input == 'F') {
				fireQ.push({ i, j });
				fireVisited[i][j] = true;
			}
		}
	}

	int ans = bfs(building, fireQ, fireVisited, size, start);

	if (ans < 0) cout << "IMPOSSIBLE" << '\n';
	else cout << ans + 1 << '\n';

	return 0;
}
