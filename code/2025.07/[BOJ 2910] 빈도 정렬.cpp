#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, c;
	cin >> n >> c;

	unordered_map<int, int> m;
	unordered_map<int, int> firstOrder;

	int input, order = 1;
	for (int i = 0; i < n; ++i) {
		cin >> input;

		++m[input];
		if (firstOrder[input] == 0)
			firstOrder[input] = order++;
	}

	vector<pair<int, int>> sortedMap(m.begin(), m.end());
	sort(sortedMap.begin(), sortedMap.end(),
		[&firstOrder](const auto& a, const auto& b) {
			if (a.second != b.second)
				return a.second > b.second;
			else
				return firstOrder[a.first] < firstOrder[b.first];
		});

	for (auto i = sortedMap.begin(); i != sortedMap.end(); ++i) {
		for (int j = 0; j < (*i).second; ++j) {
			cout << (*i).first << ' ';
		}
	}
	cout << '\n';

	return 0;
}
