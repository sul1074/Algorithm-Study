#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::pair;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

bool isIn(const pair<int, int>&, const pair<int, int>&);
int calc(const vector<vector<int>>&, const pair<int, int>&, const pair<int, int>&);
int calcShapeT(const vector<vector<int>>&, const pair<int, int>&, const pair<int, int>&);

int main(void) {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, ans = 0;
	cin >> n >> m;

	vector<vector<int>> paper(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> paper[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			ans = std::max(ans, calc(paper, { n, m }, { i, j }));
			ans = std::max(ans, calcShapeT(paper, { n, m }, { i, j }));
		}
	}

	cout << ans << '\n';

	return 0;
}

bool isIn(const pair<int, int>& boundary, const pair<int, int>& pos) {
	return (pos.first >= 0 && pos.first < boundary.first) &&
		(pos.second >= 0 && pos.second < boundary.second);
}

int calc(const vector<vector<int>>& paper, const pair<int, int>& boundary, const pair<int, int>& pos) {
	int maxSum = -1;

	// 시작 점을 빼고 나머지 3개의 점을 구하는 경우의 수는 4*4*4
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				pair<int, int> pos1 = pos;
				pair<int, int> pos2 = { pos1.first + dx[i], pos1.second + dy[i] };
				pair<int, int> pos3 = { pos2.first + dx[j], pos2.second + dy[j] };
				pair<int, int> pos4 = { pos3.first + dx[k], pos3.second + dy[k] };

				if (!isIn(boundary, pos1) || !isIn(boundary, pos2) || !isIn(boundary, pos3) || !isIn(boundary, pos4)) continue;

				// 동일한 점은 방문하면 안됨
				if (pos1 == pos2 || pos1 == pos3 || pos1 == pos4) continue;
				if (pos2 == pos3 || pos2 == pos4 || pos3 == pos4) continue;

				int p1 = paper[pos1.first][pos1.second];
				int p2 = paper[pos2.first][pos2.second];
				int p3 = paper[pos3.first][pos3.second];
				int p4 = paper[pos4.first][pos4.second];

				int sum = p1 + p2 + p3 + p4;

				maxSum = std::max(maxSum, sum);
			}
		}
	}

	return maxSum;
}

int calcShapeT(const vector<vector<int>>& paper, const pair<int, int>& boundary, const pair<int, int>& pos) {
	int maxSum = -1;
	// T 모양이 될 수 있는 좌표를, 원점을 기준으로 상대위치로 저장해둠
	vector<vector<pair<int, int>>> posTable = {
		{{0, 1}, {1, 1}, {0, 2}},
		{{1, 0}, {1, 1}, {2, 0}},
		{{1, 0}, {1, -1}, {2, 0}},
		{{0, 1}, {-1, 1}, {0, 2}}
	};


	for (int i = 0; i < 4; ++i) {
		pair<int, int> pos1 = pos;
		pair<int, int> pos2 = { pos1.first + posTable[i][0].first, pos1.second + posTable[i][0].second };
		pair<int, int> pos3 = { pos1.first + posTable[i][1].first, pos1.second + posTable[i][1].second };
		pair<int, int> pos4 = { pos1.first + posTable[i][2].first, pos1.second + posTable[i][2].second };

		if (!isIn(boundary, pos1) || !isIn(boundary, pos2) || !isIn(boundary, pos3) || !isIn(boundary, pos4)) continue;

		int p1 = paper[pos1.first][pos1.second];
		int p2 = paper[pos2.first][pos2.second];
		int p3 = paper[pos3.first][pos3.second];
		int p4 = paper[pos4.first][pos4.second];

		int sum = p1 + p2 + p3 + p4;

		maxSum = std::max(maxSum, sum);
	}

	return maxSum;
}