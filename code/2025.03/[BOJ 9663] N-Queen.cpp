#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void backtracking(vector<int>& chess, int currCol, int size, int& ans) {
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
			backtracking(chess, currCol + 1, size, ans);
		}
	}
}

int main(void) {
	int n, ans = 0;
	cin >> n;
	vector<int> chess(n);

	backtracking(chess, 0, n, ans);

	cout << ans << '\n';
}
