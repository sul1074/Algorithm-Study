#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

int n, ans = INT_MAX;
int population[11];
int visited = 0;
vector<int> group;

int getStartA() {
	for (int i = 1; i <= n; ++i) {
		if (visited & (1 << i)) return i;
	}

	return -1;
}

int getStartB() {
	for (int i = 1; i <= n; ++i) {
		if (!(visited & (1 << i))) return i;
	}
	return -1; 
}

int calcB(const vector<vector<int>>& sector, int startB) {
	queue<int> q;
	int visitedCopy = visited;
	int sum = population[startB];

	q.push(startB);
	visitedCopy |= (1 << startB);

	while (!q.empty()) {
		int curr = q.front(); q.pop();

		for (auto neighbor : sector[curr]) {
			if (visitedCopy & (1 << neighbor)) continue;

			sum += population[neighbor];
			visitedCopy |= (1 << neighbor);
			q.push(neighbor);
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (!(visitedCopy & (1 << i))) return -1;
	}

	return sum;
}

int calcA(const vector<vector<int>>& sector, int startA) {
	queue<int> q;
	q.push(startA);

	int sum = population[startA];
	int visitedCopy = (1 << startA);

	while (!q.empty()) {
		int curr = q.front(); q.pop();

		for (int neighbor : sector[curr]) {
			if ((visited & (1 << neighbor)) && !(visitedCopy & (1 << neighbor))) {
				q.push(neighbor);
				visitedCopy |= (1 << neighbor);
				sum += population[neighbor];
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		if ((visited & (1 << i)) && !(visitedCopy & (1 << i))) return -1;
	}
	
	return sum;
}


void dfs(const vector<vector<int>>& sector, int curr) {
	int startA = getStartA();

	if (startA != -1) {
		int sumA = calcA(sector, startA);
		int startB = getStartB();

		if (startB != -1) {
			int sumB = calcB(sector, startB);

			if (sumA != -1 && sumB != -1) {
				ans = min(ans, abs(sumA - sumB));
			}
		}
	}

	for (int i = curr; i <= n; ++i) {
		group.push_back(i);
		visited |= (1 << i);

		dfs(sector, i + 1);

		group.pop_back();
		visited &= ~(1 << i);
	}
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> population[i];
	}

	vector<vector<int>> sector(n + 1);

	int neiNum, nei;
	for (int i = 1; i <= n; ++i) {
		cin >> neiNum;
		for (int j = 0; j < neiNum; ++j) {
			cin >> nei;
			sector[i].push_back(nei);
		}
	}

	dfs(sector, 1);

	if (ans == INT_MAX) cout << -1 << '\n';
    else cout << ans << '\n';

	return 0;
}
