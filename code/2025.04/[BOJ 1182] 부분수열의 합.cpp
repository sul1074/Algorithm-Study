#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int sum(const vector<int>& nums) {
	int temp = 0;
	for (int n : nums)
		temp += n;

	return temp;
}

int backtracking(const vector<int>& nList, vector<int>& temp, vector<bool>& visited, int start, int end, int n, int s) {
	if (temp.size() == end) {
		if (sum(temp) == s) return 1;
		else return 0;
	}

	int ans = 0;
	for (int i = start; i < n; ++i) {
		if (visited[i]) continue;

		temp.push_back(nList[i]);
		visited[i] = true;

		ans += backtracking(nList, temp, visited, i + 1, end, n, s);

		temp.pop_back();
		visited[i] = false;
	}

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, s, ans = 0;
	cin >> n >> s;
	
	vector<bool> visited(n, false);
	vector<int> nList(n);
	for (int i = 0; i < n; ++i) {
		cin >> nList[i];
	}

	for (int i = 1; i <= n; ++i) {
		vector<int> temp;
		ans += backtracking(nList, temp, visited, 0, i, n, s);

		for (int j = 0; j < n; ++j) visited[j] = false;
	}

	cout << ans << '\n';

	return 0;
}
