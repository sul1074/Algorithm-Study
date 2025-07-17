#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void eraseFrontZero(string& str) {
	if (str.front() != '0' || (str.front() == '0' && str.size() == 1)) return;

	int idx = 1;
	for (int i = 1; i < str.size() - 1; ++i) {
		if (str[i] != '0') break;
		++idx;
	}

	str.erase(str.begin(), str.begin() + idx);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<string> numList;

	string input;
	for (int i = 0; i < n; ++i) {
		cin >> input;

		string num;
		for (auto it = input.begin(); it != input.end(); ++it) {
			if (isdigit(*it)) {
				num += *it;
			}
			else if (!isdigit(*it) && !num.empty()) {
				eraseFrontZero(num);
				numList.push_back(num);
				num.clear();
			}

		}
		if (!num.empty()) {
			eraseFrontZero(num);
			numList.push_back(num);
		}
	}

	sort(numList.begin(), numList.end(), 
		[](const string& a, const string& b) {
			if (a.size() == b.size()) {
				return a < b;
			}
			else {
				return a.size() < b.size();
			}
		});
	for (auto num : numList) {
		cout << num << '\n';
	}

	return 0;
}
