#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	if (n % 2 == 1) cout << "SK\n";
	else cout << "CY\n";

	return 0;
}
