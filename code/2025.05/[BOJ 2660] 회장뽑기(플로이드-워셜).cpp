#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> people(n + 1, vector<int>(n + 1, 10000));
	vector<int> score(n + 1);

	int a = 1, b = 1;

	while (1) {
		cin >> a >> b;

		if (a == -1 && b == -1) break;

		people[a][b] = 1;
		people[b][a] = 1;
	}

	for (int i = 1; i <= n; ++i) people[i][i] = 0;

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				people[i][j] = min(people[i][j], people[i][k] + people[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		score[i] = *max_element(people[i].begin() + 1, people[i].end());
	}

	auto it = min_element(score.begin() + 1, score.end());

	int min_score = *it;
	int cnt = count(score.begin() + 1, score.end(), min_score);
	cout << min_score << ' ' << cnt << '\n';
	for (int i = 1; i <= n; ++i) {
		if (score[i] == min_score)
			cout << i << ' ';
	}
	cout << '\n';

	return 0;
}
