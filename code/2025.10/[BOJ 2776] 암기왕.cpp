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
		int n;
		cin >> n;

		vector<int> n1(n);

		for (int i = 0; i < n; ++i) {
			cin >> n1[i];
		}

		sort(n1.begin(), n1.end());

		int m;
		cin >> m;
		
		for (int i = 0; i < m; ++i) {
			int num;
			cin >> num;

			cout << binary_search(n1.begin(), n1.end(), num) << '\n';
		}

		--t;
	}
	
	return 0;
}
