#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void sol(const string& input) {
	map<char, int> m;
	for (char ch : input) {
		++m[ch];
	}

	int oddNum = 0;
	char firstOddAlpha = '\0';
	bool isSelected = false;
	for (auto p : m) {
		if (p.second % 2 == 1) {
			++oddNum;

			if (!isSelected) {
				firstOddAlpha = p.first;
				isSelected = true;
			}
		}
	}

	if (oddNum >= 2) {
		cout << "I'm Sorry Hansoo" << '\n';

		return;
	}

	string ans;
	for (auto p : m) {
		for (int i = 0; i < int(p.second / 2); ++i) {
			ans += p.first;
		}
	}

	string temp = ans;
	reverse(temp.begin(), temp.end());

	if (firstOddAlpha) ans += firstOddAlpha;
	ans += temp;

	cout << ans << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string input;
	cin >> input;

	sol(input);

	return 0;
}
