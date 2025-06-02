#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 99999

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m;

	vector<vector<int>> cities(n + 1, vector<int>(n + 1, INF));
	for (int i = 0; i < m; ++i) {
		int a, b, t;
		cin >> a >> b >> t;

		cities[a][b] = t;
	}
	for (int i = 1; i <= n; ++i) {
		cities[i][i] = 0;
	}


	cin >> k;
	vector<int> livingCities(k);
	for (int i = 0; i < k; ++i) {
		int c;
		cin >> c;
		livingCities[i] = c;
	}

	for (int p = 1; p <= n; ++p) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (cities[i][p] == INF || cities[p][j] == INF) continue;

				cities[i][j] = min(cities[i][j], cities[i][p] + cities[p][j]);
			}
		}
	}

	vector<int> dist(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		for (auto livingCity : livingCities) {
			if (livingCity == i) continue;

			dist[i] = max(dist[i], cities[livingCity][i] + cities[i][livingCity]);
		}
	}

	int minDist = *min_element(dist.begin() + 1, dist.end());
	for (int i = 1; i <= n; ++i) {
		if (dist[i] == minDist) {
			cout << i << ' ';
		}
	}
	cout << '\n';

	return 0;
}
