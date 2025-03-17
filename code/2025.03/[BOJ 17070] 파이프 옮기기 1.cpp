#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum DirState
{
	HOR, // 수평 상태
	VER, // 수직 상태
	DIA // 대각 상태
};

typedef pair<int, int> Pos;
typedef pair<DirState, Pos> State;

bool isIn(Pos size, Pos p) {
	return p.first >= 0 && p.first < size.first 
		&& p.second >= 0 && p.second < size.second;
}

vector<State> move(const vector<vector<int>>& map, const State& state, const Pos& size) {
	vector<State> nextState;

	Pos nextHor = { state.second.first, state.second.second + 1 };
	Pos nextVer = { state.second.first + 1, state.second.second };
	Pos nextDia = { state.second.first + 1, state.second.second + 1 };

	bool canHorMove = isIn(size, nextHor) && map[state.second.first][state.second.second + 1] == 0;
	bool canVerMove = isIn(size, nextVer) && map[state.second.first + 1][state.second.second] == 0;
	bool canDiaMove = isIn(size, nextDia) && canHorMove && canVerMove && map[state.second.first + 1][state.second.second + 1] == 0;

	if (state.first == DirState::HOR) {
		if (canHorMove) nextState.push_back({DirState::HOR, nextHor });
		if (canDiaMove) nextState.push_back({ DirState::DIA, nextDia });
	}
	else if (state.first == DirState::VER) {
		if (canVerMove) nextState.push_back({ DirState::VER, nextVer });
		if (canDiaMove) nextState.push_back({ DirState::DIA, nextDia });
	}
	else {
		if (canHorMove) nextState.push_back({ DirState::HOR, nextHor });
		if (canVerMove) nextState.push_back({ DirState::VER, nextVer });
		if (canDiaMove) nextState.push_back({ DirState::DIA, nextDia });
	}

	return nextState;
}

int bfs(const vector<vector<int>>& map, const Pos& size) {
	int cnt = 0;
	queue<State> q;
	q.push({ { DirState::HOR }, { 0, 1 } });

	while (!q.empty()) {
		State curr = q.front(); q.pop();

		if (curr.second.first + 1 == size.first && curr.second.second + 1== size.second) {
			++cnt;
			continue;
		}

		vector<State> next = move(map, curr, size);

		if (next.size() > 0) {
			for (auto s : next) q.push(s);
		}
	}

	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> map(n, vector<int>(n));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}

	int ans = bfs(map, {n, n});
	cout << ans << '\n';

	return 0;
}
