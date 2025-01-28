#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::queue;
using std::string;

int opD(int);
int opS(int);
int opL(int);
int opR(int);
string bfs(int, int);

int main(void) {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for (int time = 0; time < t; ++time) {
		int a, b;
		cin >> a >> b;

		cout << bfs(a, b) << '\n';
	}

	return 0;
}

int opD(int n) {
	return (n * 2) % 10000;
}

int opS(int n) {
	return (n > 0) ? n - 1 : 9999;
}

int opL(int n) {
	int d1 = n / 1000;
	return (n % 1000) * 10 + d1;
}

int opR(int n) {
	int d4 = n % 10;
	return d4 * 1000 + n / 10;
}

string bfs(int a, int b) {
	using Func = int(*)(int);
	const Func ops[4] = { opD, opS, opL, opR };
	const char opStr[4] = { 'D', 'S', 'L', 'R' };

	std::pair<int, char> trace[10000]; // 이전 값과 연산을 저장. 방문 여부 체크로도 사용
	std::fill(trace, trace + 10000, std::make_pair(-1, '\0'));
	queue<int> q;

	q.push(a);
	trace[a] = { a, '\0' };

	while (!q.empty()) {
		int turnSize = q.size();

		for (int t = 0; t < turnSize; ++t) {
			int n = q.front();
			q.pop();

			if (n == b) {
				string path;
				for (int cur = b; cur != a; cur = trace[cur].first) {
					path += trace[cur].second;
				}
				// 뒤에서부터 추적했으니 뒤집어 주어야 함.
				std::reverse(path.begin(), path.end());

				return path;
			}

			for (int i = 0; i < 4; ++i) {
				int rst = ops[i](n);

				// 이미 사용된 값이면 스킵
				if (trace[rst].first != -1) continue;

				trace[rst] = { n, opStr[i] };
				q.push(rst);
			}
		}
	}

	return {};
}