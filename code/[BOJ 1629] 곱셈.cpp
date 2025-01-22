#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main(void) {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> digitCount(10, 0);
	int n;
	cin >> n;
	
	while (n > 0) {
		digitCount[n % 10]++;
		n /= 10;
	}

	for (int i = digitCount.size() - 1; i >= 0; i--) {
		for (int j = 0; j < digitCount[i]; j++) {
			cout << i;
		}
	}

	return 0;
}