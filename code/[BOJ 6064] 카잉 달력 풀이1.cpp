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
	// 두 수가 같으면, 더해진 횟수도 당연히 동일함.
	if (x == y) return x;

	// m을 계속 더해줌으로써, x값을 고정함. 해당 x값에 해당하는 y값 조합이 나타나면 답임
	while (x <= lcm(m, n)) {
		if (x % n == y % n) {
			return x;
		}
		x += m;
	}

	return -1;
}