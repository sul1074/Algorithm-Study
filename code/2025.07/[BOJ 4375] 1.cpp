#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while (cin >> n) {
		int cnt = 1;
		unsigned long long i = 1;

		while (!(i % n == 0)) {
			i = (i * 10 + 1) % n;
			++cnt;
		}

		cout << cnt << '\n';
	}

	return 0;
}
