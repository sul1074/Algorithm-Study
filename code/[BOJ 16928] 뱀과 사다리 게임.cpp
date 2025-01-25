#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::cin;
using std::cout;
using std::vector;
using std::pair;

int bfs(int start, const vector<int>& board);

int main(void) {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> board(101);
	for (int i = 1; i < 101; i++) {
		board[i] = i;
	}

	for (int i = 0; i < n + m; i++) {
		int ent, dest;
		cin >> ent >> dest;

		board[ent] = dest;
	}

	cout << bfs(1, board) << '\n';

	return 0;
}

int bfs(int start, const vector<int>& board) {
	vector<bool> visited(101, false); // 메모리 관리를 위해 방문한 위치는 다시 방문 X
	std::queue<int> q; // x위치를 큐에 저장

	q.push(start);
	visited[start] = true;
	int cnt = 0;

	while (!q.empty()) {
		// 이번 턴에 순회해야 할 경우의 수
		int turnLen = q.size();

		for (int i = 0; i < turnLen; i++) {
			// y위치를 curr로
			int curr = board[q.front()];
			q.pop();

			for (int dice = 1; dice <= 6; ++dice) {
				int nx = curr + dice;

				if (nx > 100 || visited[nx]) continue;
				if (nx == 100) return cnt + 1;

				q.push(nx);
				visited[nx] = true;
			}
		}

		++cnt;
	}
}