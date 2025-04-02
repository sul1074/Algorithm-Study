#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int h, w, n, m;
	cin >> h >> w >> n >> m;

	int col = (w + m) / (m + 1);
	int row = (h + n) / (n + 1);

	cout << col * row << '\n';

	return 0;
}
