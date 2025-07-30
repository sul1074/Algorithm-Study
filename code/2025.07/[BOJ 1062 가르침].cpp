#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n, k;
string words[50];

int ans = -1;
bool visited[26];

bool isDefault(char ch) {
	return ch == 'a' || ch == 'c' || ch == 'i' || ch == 'n' || ch == 't';
}

bool canRead(const string& word) {
	int cnt = 0;

	for (const auto& ch : word) {
		if (visited[ch - 'a']) ++cnt;
	}

	return cnt == word.size();
}

int check() {
	int cnt = 0;

	for (int i = 0; i < n; ++i) {
		if (canRead(words[i])) ++cnt;
	}

	return cnt;
}

void backtracking(int depth, int start) {
	if (ans == n) return;

	if (depth >= k - 5) {
		ans = max(ans, check());
		return;
	}

	for (char c = start; c <= 'z'; ++c) {
		if (visited[c - 'a'] || isDefault(c)) continue;

		visited[c - 'a'] = true;
		backtracking(depth + 1, c);
		visited[c - 'a'] = false;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	string str;
	for (int i = 0; i < n; ++i) {
		cin >> str;

		sort(str.begin(), str.end());
		str.erase(unique(str.begin(), str.end()), str.end());

		for (auto ch : str) {
			if (!isDefault(ch)) words[i] += ch;
		}
	}

	if (k < 5) {
		cout << 0 << '\n';
		return 0;
	}

	backtracking(0, 'a');
	cout << ans << '\n';

	return 0;
}

/*
* acint(5개)은 무조건 가르쳐야 함. -> anta tica
*/
