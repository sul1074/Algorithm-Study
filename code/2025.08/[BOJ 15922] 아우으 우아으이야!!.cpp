#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Line {
	int s, e;
};

vector<Line> input(100000);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, ans = 0;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> input[i].s >> input[i].e;
	}

	int prev = input[0].s;
	for (int i = 0; i < n; ++i) {
		int start = (prev > input[i].s) ? prev : input[i].s;

		if (start >= input[i].e) continue;

		ans += input[i].e - start;
		prev = input[i].e;
	}

	cout << ans << '\n';

	return 0;
}
