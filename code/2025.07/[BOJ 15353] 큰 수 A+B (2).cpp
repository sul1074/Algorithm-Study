#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool carry = false;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string n1, n2, ans;
	cin >> n1 >> n2;

	int idx1 = n1.size() - 1, idx2 = n2.size() - 1;

	while (idx1 >= 0 || idx2 >= 0) {
		int sum = 0;

		if (idx1 >= 0) sum += n1[idx1--] - '0';
		if (idx2 >= 0) sum += n2[idx2--] - '0';

		if (carry) {
			++sum;
			carry = false;
		}

		carry = sum >= 10;
		ans += to_string(sum % 10);
	}

	if (carry) ans += '1';
	reverse(ans.begin(), ans.end());

	cout << ans << '\n';

	return 0;
}
