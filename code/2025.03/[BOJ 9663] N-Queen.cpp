#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int ans = 0;

void backtracking(vector<int>& chess, int currCol, int size) {
	if (currCol == size) {
		++ans;
		return;
	}

	for (int rowPos = 0; rowPos < size; ++rowPos) {
		bool isPromising = true;

		for (int col = 0; col < currCol; ++col) {
			if (chess[col] == rowPos || abs(chess[col] - rowPos) == abs(col - currCol)) {
				isPromising = false;
				break;
			}
		}

		if (isPromising) {
			chess[currCol] = rowPos;
			backtracking(chess, currCol + 1, size);
		}
	}
}

int main(void) {
	int n;
	cin >> n;
	vector<int> chess(n);

	backtracking(chess, 0, n);

	cout << ans << '\n';
}
