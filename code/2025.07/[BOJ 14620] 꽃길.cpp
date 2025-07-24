#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int dr[4] = { 1, 0, -1, 0 };
const int dc[4] = { 0, 1, 0, -1 };

int garden[10][10];
int n;

struct Pos {
	int r, c;

	bool operator==(const Pos& other) {
		return other.r == r && other.c == c;
	}
	int operator-(const Pos& other) {
		return abs(other.r - r) + abs(other.c - c);
	}
};

bool isIn(const Pos& p) {
	return p.r >= 0 && p.r < n && p.c >= 0 && p.c < n;
}

int calc(const Pos& p1, const Pos& p2, const Pos& p3) {
	bool visited[10][10] = { false };

	int price = garden[p1.r][p1.c]
		+ garden[p2.r][p2.c]
		+ garden[p3.r][p3.c];

	visited[p1.r][p1.c] = true;
	visited[p2.r][p2.c] = true;
	visited[p3.r][p3.c] = true;

	for (int i = 0; i < 4; ++i) {
		Pos p1N = { p1.r + dr[i], p1.c + dc[i] };
		Pos p2N = { p2.r + dr[i], p2.c + dc[i] };
		Pos p3N = { p3.r + dr[i], p3.c + dc[i] };

		if (visited[p1N.r][p1N.c] || visited[p2N.r][p2N.c] || visited[p3N.r][p3N.c]) return -1;

		price += garden[p1N.r][p1N.c];
		price += garden[p2N.r][p2N.c];
		price += garden[p3N.r][p3N.c];
		visited[p1N.r][p1N.c] = true;
		visited[p2N.r][p2N.c] = true;
		visited[p3N.r][p3N.c] = true;
	}

	return price;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<Pos> comb;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> garden[i][j];
		}
	}

	for (int i = 1; i < n - 1; ++i) {
		for (int j = 1; j < n - 1; ++j) {
			comb.push_back({ i, j });
		}
	}

	int ans = 21470000;
	int sz = comb.size();
	for (int i = 0; i < sz; ++i) {
		for (int j = i + 1; j < sz; ++j) {
			for (int k = j + 1; k < sz; ++k) {
				Pos p1 = comb[i];
				Pos p2 = comb[j];
				Pos p3 = comb[k];

				if (p1 - p2 < 3 || p1 - p3 < 3 || p2 - p3 < 3) continue;

				int price = calc(p1, p2, p3);

				if (price < 0) continue;
				ans = min(ans, price);
			}
		}
	}

	cout << ans << '\n';

	return 0;
}