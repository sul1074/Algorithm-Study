#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pos {
	int r, c;
};

struct Line {
	Pos start, end;
};

bool map[101][101];

int rectDr[3] = { 1, 0, 1 };
int rectDc[3] = { 0, 1, 1 };
bool isRect(const Pos& p) {
	if (!map[p.r][p.c]) return false;

	for (int i = 0; i < 3; ++i) {
		if (p.r + rectDr[i] > 100 || p.c + rectDc[i] > 100
			|| !map[p.r + rectDr[i]][p.c + rectDc[i]]) return false;
	}

	return true;
}

int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { 1, 0, -1, 0 };
void dragonCurve(Pos start, int d, int g) {
	vector<Line> lines;
	lines.push_back({ start, { start.r + dr[d], start.c + dc[d]} });
	
	for (int i = 0; i < g; ++i) {
		Pos pivot = lines.back().end;
		int sz = lines.size();

		for (int j = sz - 1; j > -1; --j) {
			Line curr = lines[j];

			Pos rotatedStart = {
				pivot.r + (curr.start.c - pivot.c),
				pivot.c - (curr.start.r - pivot.r)
			};
			Pos rotatedEnd = {
				pivot.r + (curr.end.c - pivot.c),
				pivot.c - (curr.end.r - pivot.r)
			};

			lines.push_back({ rotatedEnd, rotatedStart });
		}
	}

	for (const auto& l : lines) {
		map[l.start.r][l.start.c] = true;
		map[l.end.r][l.end.c] = true;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int x, y, d, g;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y >> d >> g;
		dragonCurve({y, x}, d, g);
	}

	int ans = 0;
	for (int i = 0; i <= 100; ++i) {
		for (int j = 0; j <= 100; ++j) {
			if (isRect({i, j})) ++ans;
		}
	}
	cout << ans << '\n';
	
	return 0;
}
