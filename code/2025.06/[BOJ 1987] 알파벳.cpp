#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pos;

int dx[4] = { 1, 0, -1 ,0 };
int dy[4] = { 0, 1, 0, -1 };

int ans = 0;

bool is_in(const Pos& curr, const Pos& size) {
	return curr.first >= 0 && curr.first < size.first
		&& curr.second >= 0 && curr.second < size.second;
}

int dfs(const vector<vector<char>>& board, vector<bool>& visited, const Pos& size, const Pos& p) {

	int max_cnt = 1;

	for (int i = 0; i < 4; ++i) {
		int nx = p.first + dx[i];
		int ny = p.second + dy[i];
		
		if (!is_in({ nx, ny }, size)
			|| visited[board[nx][ny] - 'A']) continue;

		visited[board[nx][ny] - 'A'] = true;

		int cnt = 1 + dfs(board, visited, size, { nx, ny });
		max_cnt = max(cnt, max_cnt);

		visited[board[nx][ny] - 'A'] = false;
	}

	ans = max(ans, max_cnt);

	return max_cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Pos size;
	cin >> size.first >> size.second;

	vector<bool> visited(26, false);
	vector<vector<char>> board(size.first, vector<char>(size.second));
	
	for (int i = 0; i < size.first; ++i) {
		for (int j = 0; j < size.second; ++j) {
			cin >> board[i][j];
		}
	}

	visited[board[0][0] - 'A'] = true;

	dfs(board, visited, size, { 0, 0 });

	cout << ans << '\n';

	return 0;
}
