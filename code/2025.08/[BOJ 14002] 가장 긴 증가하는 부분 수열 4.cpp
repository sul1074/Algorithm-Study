#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Lis {
	int len;
	vector<int> p;
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> permut(n);
	for (int i = 0; i < n; ++i) {
		cin >> permut[i];
	}

	vector<Lis> lis(n, { 1, {} });
	for (int i = 0; i < n; ++i) {
		lis[i].p.push_back(permut[i]);
	}
	for (int i = 1; i < n; ++i) {
		int curr = permut[i];
		int maxIdx = 0, maxLen = -1;

		for (int j = 0; j < i; ++j) {
			if (curr > permut[j]) {
				if (maxLen < lis[j].len) {
					maxLen = lis[j].len;
					maxIdx = j;
				}
			}
		}

		if (maxLen + 1 > lis[i].len) {
			lis[i].len = maxLen + 1;
			lis[i].p = lis[maxIdx].p;
			lis[i].p.push_back(permut[i]);
		}
	}

	int idx = -1, maxLen = -1;
	for (int i = 0; i < n; ++i) {
		if (maxLen < lis[i].len) {
			maxLen = lis[i].len;
			idx = i;
		}
	}

	cout << lis[idx].len << '\n';
	for (auto num : lis[idx].p) {
		cout << num << ' ';
	}
	cout << '\n';

	return 0;
}
