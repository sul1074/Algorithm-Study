#include <iostream>
#include <vector>

using namespace std;

void backtracking(vector<int>& temp, vector<bool>& visited, int n, int m) {
	if (temp.size() == m) {
		for (int n : temp) {
			cout << n << ' ';
		}
		cout << '\n';

		return;
	}

	for (int i = 1; i <= n; ++i) {
		if (visited[i - 1]) continue;

		temp.push_back(i);
		visited[i - 1] = true;

		backtracking(temp, visited, n, m);

		temp.pop_back();
		visited[i - 1] = false;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> temp;
	vector<bool> visited(n, false);
	backtracking(temp, visited, n, m);

	return 0;
}
