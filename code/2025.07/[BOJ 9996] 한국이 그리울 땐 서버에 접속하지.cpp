#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sol(const string& leftPattern, const string& rightPattern, 
	const string& file) {
	
	if (file.size() < leftPattern.size() + rightPattern.size()) {
		cout << "NE" << '\n';

		return;
	}

	string left = file.substr(0, leftPattern.size());
	string right = file.substr(file.size() - rightPattern.size(), rightPattern.size());

	if (left == leftPattern && right == rightPattern) cout << "DA" << '\n';
	else cout << "NE" << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string pattern;
	cin >> pattern;


	int idx = -1;
	for (int i = 0; i < pattern.size(); ++i) {
		if (pattern[i] == '*') {
			idx = i;
			break;
		}
	}

	string leftPattern = pattern.substr(0, idx);
	string rightPattern = pattern.substr(idx + 1, pattern.size() - (idx + 1));

	string file;
	for (int i = 0; i < n; ++i) {
		cin >> file;

		sol(leftPattern, rightPattern, file);
	}

	return 0;
}
