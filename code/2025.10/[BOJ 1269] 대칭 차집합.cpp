#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	unordered_set<int> us;
	int a, b, commonNumCnt = 0;
	cin >> a >> b;

	for (int i = 0; i < a; ++i) {
		int n;
		cin >> n;

		us.insert(n);
	}

	for (int i = 0; i < b; ++i) {
		int n;
		cin >> n;

		if (us.count(n)) ++commonNumCnt;
		else us.insert(n);
	}

	cout << us.size() - commonNumCnt << '\n';

	return 0;
}
