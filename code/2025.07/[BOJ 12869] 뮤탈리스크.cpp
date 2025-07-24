#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int scvNum;
int scv[3] = { -1 };
bool visited[61][61][61] = { false };
const int attack[6][3] = { 
	{ 9, 3, 1 },
	{ 9, 1, 3 },
	{ 3, 9, 1 },
	{ 3, 1, 9 },
	{ 1, 9, 3 },
	{ 1, 3, 9 }
};

struct SCV {
	int a, b, c;
};

int bfs() {
	queue<SCV> q;
	q.push ({scv[0], scv[1], scv[2]});

	int ans = 0;
	while (!visited[0][0][0]) {
		int turn = q.size();

		for (int i = 0; i < turn; ++i) {
			SCV s = q.front(); q.pop();

			for (int i = 0; i < 6; ++i) {
				SCV next = { 
					max(0, s.a - attack[i][0]),
					max(0, s.b - attack[i][1]),
					max(0, s.c - attack[i][2])
				};

				if (visited[next.a][next.b][next.c]) continue;
		
				q.push(next);
				visited[next.a][next.b][next.c] = true;
			}
		}

		++ans;
	}

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> scvNum;
	for (int i = 0; i < scvNum; ++i) {
		cin >> scv[i];
	}

	cout << bfs() << '\n';

	return 0;
}
