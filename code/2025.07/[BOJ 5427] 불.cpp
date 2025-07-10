#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };

struct Pos {
	int r;
	int c;
};

bool isIn(const Pos& size, const Pos& curr) {
	return curr.r >= 0 && curr.r < size.r
		&& curr.c >= 0 && curr.c < size.c;
}

bool isEscaped(const Pos& size, const Pos& curr) {
	return curr.r == 0 || curr.c == 0 ||
		curr.r == size.r - 1 || curr.c == size.c - 1;
}

int bfs(const vector<vector<char>>& b, const vector<Pos>& fireList,
	const Pos& size, const Pos& start) {
	queue<Pos> personQ;
	queue<Pos> fireQ;
	vector<vector<bool>> visited_person(size.r, vector<bool>(size.c, false));
	vector<vector<bool>> visited_fire(size.r, vector<bool>(size.c, false));

	personQ.push(start);
	visited_person[start.r][start.c] = true;

	for (auto firePos : fireList) {
		fireQ.push(firePos);
		visited_fire[firePos.r][firePos.c] = true;
	}

	int time = 1;

	while (!personQ.empty()) {
		int fireTurn = fireQ.size();
		for (int i = 0; i < fireTurn; ++i) {
			Pos firePos = fireQ.front(); fireQ.pop();

			for (int i = 0; i < 4; ++i) {
				Pos diffusion = { firePos.r + dr[i], firePos.c + dc[i] };

				if (isIn(size, diffusion) && b[diffusion.r][diffusion.c] == '.' && !visited_fire[diffusion.r][diffusion.c]) {
					visited_fire[diffusion.r][diffusion.c] = true;
					fireQ.push({ diffusion.r, diffusion.c });
				}
			}
		}

		int personTurn = personQ.size();
		for (int i = 0; i < personTurn; ++i) {
			Pos curr = personQ.front(); personQ.pop();

			if (isEscaped(size, curr)) return time;

			for (int i = 0; i < 4; ++i) {
				Pos next = { curr.r + dr[i], curr.c + dc[i] };

				if (isIn(size, next) 
					&& b[next.r][next.c] == '.' 
					&& !visited_fire[next.r][next.c]
					&& !visited_person[next.r][next.c]) {

					personQ.push(next);
					visited_person[next.r][next.c] = true;
				}
			}
		}

		++time;
	}

	return -1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	cin >> num;

	for (int t = 0; t < num; ++t) {
		Pos size, start;
		cin >> size.c >> size.r;

		vector<Pos> fireList;
		vector<vector<char>> b(size.r, vector<char>(size.c));
		for (int i = 0; i < size.r; ++i) {
			for (int j = 0; j < size.c; ++j) {
				char input;
				cin >> input;
				b[i][j] = input;

				if (input == '@') {
					start.r = i;
					start.c = j;
					b[i][j] = '.';
				}
				else if (input == '*') {
					fireList.push_back({ i, j });
				}
			}
		}

		int ans = bfs(b, fireList, size, start);

		if (ans < 0) cout << "IMPOSSIBLE" << '\n';
		else cout << ans << '\n';
	}

	return 0;
}
