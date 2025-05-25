#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	priority_queue<int, vector<int>, greater<int>> pq;

	int n;
	cin >> n;

	int input;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> input;
			pq.push(input);
		}

		while (pq.size() > n) pq.pop();
	}

	cout << pq.top() << '\n';

	return 0;
}
