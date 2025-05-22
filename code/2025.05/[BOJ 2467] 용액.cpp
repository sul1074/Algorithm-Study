#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef pair<int, int> Ans;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Ans ans;
	int n, tPoint, min = INT_MAX;
	cin >> n;

	vector<int> sol(n);
	for (int i = 0; i < n; ++i) {
		cin >> sol[i];
	}	
	
	int start = 0;
	int end = n - 1;
	
	while (start < end) {
		int a = sol[start];
		int b = sol[end];
		int sum = a + b;

		if (sum == 0) {
			ans.first = a;
			ans.second = b;
			break;
		}

		else if (abs(sum) < min) {
			min = abs(sum);
			ans.first = a;
			ans.second = b;
		}

		if (sum < 0) ++start;
		else --end;
	}

	cout << ans.first << ' ' << ans.second << '\n';

	return 0;
}
