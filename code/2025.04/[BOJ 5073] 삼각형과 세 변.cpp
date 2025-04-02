#include <iostream>
#include <algorithm>

using namespace std;

bool isPossible(int n1, int n2, int n3) {
	int maxSide = max(n1, max(n2, n3));
	int twoSideSum = n1 + n2 + n3 - maxSide;

	return maxSide < twoSideSum;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;

		if (n1 == 0 && n2 == 0 && n3 == 0) break;

		if (isPossible(n1, n2, n3)) {
			if (n1 == n2 && n2 == n3) cout << "Equilateral\n";
			else if (n1 == n2 || n2 == n3 || n1 == n3) cout << "Isosceles\n";
			else cout << "Scalene\n";
		}
		else {
			cout << "Invalid\n";
		}
	}

	return 0;
}
