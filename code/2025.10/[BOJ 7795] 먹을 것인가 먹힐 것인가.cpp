#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t > 0) {
		int n, m;
		cin >> n >> m;

		int cnt = 0;

		vector<int> a(n), b(m);

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		for (int i = 0; i < m; ++i) {
			cin >> b[i];
		}
		
		sort(a.begin(), a.end(), [](const int& a, const int& b) {
			return a > b;
		});
		sort(b.begin(), b.end());

		int idx = m - 1;
		for (const auto& num : a) {
			for (int i = idx; i > -1; --i) {
				if (num > b[i]) {
					cnt += i + 1;
					break;
				}
				--idx;
			}
		}

		cout << cnt << '\n';
		--t;
	}

	return 0;
}
