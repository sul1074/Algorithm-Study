#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[6] = { 1, 0, 0, -1, 0, 0 };
int dy[6] = { 0, 1, 0, 0, -1, 0 };
int dz[6] = { 0, 0, 1, 0, 0, -1 };

struct Point {
	int x;
	int y;
	int z;

	bool operator==(const Point& p) const {
		return x == p.x && y == p.y && z == p.z;
	}
};

bool isIn(const Point& size, const Point& p) {
	return p.x >= 0 && p.x < size.x && p.y >= 0 && p.y < size.y
		&& p.z >= 0 && p.z < size.z;
}

int bfs(vector<vector<vector<char>>>& b, 
	const Point& size, const Point& start, const Point& end) {
	queue<Point> q;
	q.push(start);

	b[start.x][start.y][start.z] = '#';

	int cnt = 0;

	while (!q.empty()) {
		int turnTime = q.size();

		for (int t = 0; t < turnTime; ++t) {
			Point curr = q.front(); q.pop();

			if (curr == end) return cnt;

			for (int i = 0; i < 6; ++i) {
				Point next = { curr.x + dx[i], curr.y + dy[i], curr.z + dz[i] };

				if (!isIn(size, next) || b[next.x][next.y][next.z] == '#') continue;

				q.push(next);
				b[next.x][next.y][next.z] = '#';
			}
		}
		++cnt;
	}

	return -1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Point size;
	while (1) {
		cin >> size.x >> size.y >> size.z;

		if (size.x == 0 && size.y == 0 && size.z == 0) break;

		Point start, end;

		vector<vector<vector<char>>> b(size.x, 
			vector<vector<char>>(size.y, vector<char>(size.z)));
		
		for (int i = 0; i < size.x; ++i) {
			for (int j = 0; j < size.y; ++j) {
				for (int k = 0; k < size.z; ++k) {
					char sector;
					cin >> sector;

					b[i][j][k] = sector;

					if (sector == 'S') {
						start.x = i;
						start.y = j;
						start.z = k;
					}
					else if (sector == 'E') {
						end.x = i;
						end.y = j;
						end.z = k;
					}
				}
			}
		}

		int time =  bfs(b, size, start, end);

		if (time < 0) cout << "Trapped!" << '\n';
		else cout << "Escaped in " << time << " minute(s)." << '\n';
	}

	return 0;
}
