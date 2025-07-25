#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

int k;
char input[9] = { '\0' };
bool visited[10] = { false };

long long maxAns = LONG_MIN;
long long minAns = LONG_MAX;

void printAns() {
	string maxStr = to_string(maxAns);
	string minStr = to_string(minAns);

	while (maxStr.length() < k + 1) {
		maxStr = '0' + maxStr;
	}
	while (minStr.length() < k + 1) {
		minStr = '0' + minStr;
	}

	cout << maxStr << '\n';
	cout << minStr << '\n';
}

void backtracking(long long temp, int prev, int depth) {
	if (depth == k) {
		minAns = min(minAns, temp);
		maxAns = max(maxAns, temp);

		return;
	}

	for (int i = 0; i <= 9; ++i) {
		if (visited[i]) continue;

		if (depth != -1) {
			char sign = input[depth];
			if (sign == '<' && prev > i) continue;
			if (sign == '>' && prev < i) continue;
		}

		visited[i] = true;
		backtracking(temp * 10 + i, i, depth + 1);
		visited[i] = false;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> input[i];
	}

	backtracking(0, 0, -1);
	printAns();

	return 0;
}
