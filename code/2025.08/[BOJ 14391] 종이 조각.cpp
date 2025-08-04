#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n, m;
string paper[4];
int ans = -1;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> paper[i];
	}

	int total = 1 << (n * m);
	for (int mask = 0; mask < total; ++mask) {
		int sum = 0;

		// 가로 조각 계산
		
		for (int i = 0; i < n; ++i) {
			int temp = 0;
			for (int j = 0; j < m; ++j) {
				int idx = i * m + j;

				if (mask & (1 << idx)) {
					temp = temp * 10 + (paper[i][j] - '0');
				}
				else {
					sum += temp;
					temp = 0;
				}
			}
			sum += temp;
		}

		// 세로 조각 계산
		for (int j = 0; j < m; ++j) {
			int temp = 0;
			for (int i = 0; i < n; ++i) {
				int idx = i * m + j;

				if (!(mask & (1 << idx))) {
					temp = temp * 10 + (paper[i][j] - '0');
				}
				else {
					sum += temp;
					temp = 0;
				}
			}
			sum += temp;
		}

		ans = max(sum, ans);
	}

	cout << ans << '\n';

	return 0;
}
