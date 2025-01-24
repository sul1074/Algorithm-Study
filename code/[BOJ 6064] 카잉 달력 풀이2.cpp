#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;

int gcd(int, int);
int lcm(int, int);
int calc(int, int, int, int);

int main(void) {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for (int time = 0; time < t; ++time) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		cout << calc(m, n, x, y) << '\n';
	}

	return 0;
}

int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int lcm(int a, int b) {
	return (a / gcd(a, b)) * b;
}

int calc(int m, int n, int x, int y) {
	int boundary = lcm(m, n);

	// x와 y를 증분시켜 최소 공배수 내에서 일치하는 연도를 찾음
	while (x <= boundary && y <= boundary) {
		if (x == y) return x;
		
		if (x < y) x += m;
		else y += n;
	}

	return -1;
}