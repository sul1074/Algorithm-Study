#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int h, w;
char sector[100][100];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> h >> w;

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> sector[i][j];
		}
	}

	for (int i = 0; i < h; ++i) {
		bool firstCloud = sector[i][0] == 'c';
		int cnt = 0;

		if (firstCloud) cout << cnt++ << ' ';
		else cout << -1 << ' ';

		for (int j = 1; j < w; ++j) {
			if (firstCloud) {
				if (sector[i][j] == 'c') cnt = 0;
				cout << cnt++ << ' ';
			}
			else {
				if (sector[i][j] == 'c') {
					firstCloud = true;
					cout << cnt++ << ' ';
				}
				else cout << -1 << ' ';
			}

		}
		cout << '\n';
	}

	return 0;
}
