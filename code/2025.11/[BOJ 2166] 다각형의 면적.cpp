#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>

using namespace std;

struct Pos {
	int x, y;
};

typedef long long ll;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<Pos> points(n + 1);
	for (int i = 0; i < n; ++i) {
		cin >> points[i].x >> points[i].y;
	}
	points[n] = points.front();

	double rightDigSum = 0, leftDigSum = 0;
	Pos prev = points.front();

	for (int i = 1; i < n + 1; ++i) {
		rightDigSum += (double)prev.x * points[i].y;
		leftDigSum += (double)prev.y * points[i].x;
		prev = points[i];
	}

	double ans = abs(rightDigSum - leftDigSum) / 2;

	cout << fixed;
	cout.precision(1);
	cout << ans << '\n';

	return 0;
}
