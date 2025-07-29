#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
vector<int> num;
vector<char> op;
int ans = INT_MIN;

int calc(int a, int b, char oper) {
	if (oper == '+') return a + b;
	else if (oper == '-') return a - b;
	else if (oper == '*') return a * b;
}

void backtracking(int depth, int curr) {
	if (depth >= op.size()) {
		ans = max(ans, curr);
		return;
	}

	backtracking(depth + 1, calc(curr, num[depth + 1], op[depth]));

	if (depth + 1 < op.size()) {
		int temp = calc(num[depth + 1], num[depth + 2], op[depth + 1]);
		backtracking(depth + 2, calc(curr, temp, op[depth]));
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	char ch;
	for (int i = 0; i < n; ++i) {
		cin >> ch;
		if (isdigit(ch)) num.push_back(ch - '0');
		else op.push_back(ch);
	}

	backtracking(0, num.front());
	cout << ans << '\n';

	return 0;
}
