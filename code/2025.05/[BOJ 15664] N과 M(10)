#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtracking(const vector<int>& nList, vector<int>& p, int start, int n, int m) {
	if (p.size() == m) {
		for (auto n : p) {
			cout << n << ' ';
		}
		cout << '\n';

		return;
	}

	int prev = -1;
	for (int i = start; i < n; ++i) {
		if (prev != -1 && prev == nList[i]) continue;

		p.push_back(nList[i]);

		backtracking(nList, p, i + 1, n, m);
		
		p.pop_back();
		prev = nList[i];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> nList(n);
	for (int i = 0; i < n; ++i) cin >> nList[i];
	sort(nList.begin(), nList.end());

	vector<int> p;

	backtracking(nList, p, 0, n, m);

	return 0;
}
