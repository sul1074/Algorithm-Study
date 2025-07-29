#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int n, k;
int brother[500001];
int subin[2][500001];
int ans = INT_MAX;

const int dx[3] = { 0, 1, -1 };

void bfs() {
	queue<int> q;
	q.push(n);

	int time = 0;
	while (!q.empty()) {
		int turn = q.size();

		for (int i = 0; i < turn; ++i) {
			int curr = q.front(); q.pop();

			int next, tempNextTime = time + 1;
			for (int i = 0; i < 3; ++i) {
				if (i == 0) next = curr * 2;
				else next = curr + dx[i];

				if (next < 0 || next > 500000 || subin[tempNextTime & 1][next] > 0) continue;

				subin[tempNextTime & 1][next] = subin[time & 1][curr] + 1;
				q.push(next);

				if (brother[next] > 0) {
					if (brother[next] == subin[tempNextTime & 1][next]) {
						ans = min(ans, brother[next]);
					}
					if (brother[next] > subin[tempNextTime & 1][next]
						&& ((brother[next] - subin[tempNextTime & 1][next]) % 2 == 0)) {
						ans = min(ans, brother[next]);
					}
				}
			}
		}

		++time;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	if (n == k) {
		cout << 0 << '\n';
		return 0;
	}

	int cul = 1;
	int time = 1;
	while (1) {
		k += cul++;

		if (k > 500000) break;
		brother[k] = time++;
	}
	bfs();

	if (ans == INT_MAX) cout << -1 << '\n';
	else cout << ans << '\n';

	return 0;
}
