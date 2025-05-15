#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

bool visited[1000001] = { false };

int bfs(const int* info) {
	int cnt = 0;
	queue<int> q;
	q.push(info[1]);
	visited[info[1]] = true;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		if (curr == info[2]) return cnt;

		int next;

		if (curr > info[2]) {
			if (curr - info[4] < 1) next = curr + info[3];
			else next = curr - info[4];
		}

		else {
			if (curr + info[3] > info[0]) next = curr - info[4];
			else next = curr + info[3];
		}

		if (visited[next] || next <= 0 || next > info[0]) continue;

		q.push(next);
		visited[next] = true;
		++cnt;
	}

	return -1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int info[5]; // f, s, g, u, d
	for (int i = 0; i < 5; ++i)
		cin >> info[i];

	int ans = bfs(info);

	if (ans < 0)
		cout << "use the stairs" << '\n';
	else
		cout << ans << '\n';

	return 0;
}
