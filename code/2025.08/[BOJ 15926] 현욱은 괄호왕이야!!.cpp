#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string input;
	int n, ans = 0;

	cin >> n;
	cin >> input;

	stack<int> s;
	s.push(-1);

	for (int i = 0; i < n; ++i) {
		if (input[i] == '(') s.push(i);
		else if (input[i] == ')') {
			s.pop();

			if (s.empty()) s.push(i);
			else ans = max(ans, i - s.top());
		}
	}

	cout << ans << '\n';

	return 0;
}
