#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string input, boom;
	cin >> input >> boom;

	int boomLen = boom.size();
	string res = "";

	for (char c : input) {
		res += c;

		if (res.size() >= boomLen) {
			string sub = res.substr(res.size() - boomLen);
			
			if (sub == boom) {
				res.erase(res.size() - boomLen);
			}
		}
	}

	if (res.empty()) cout << "FRULA" << '\n';
	else cout << res << '\n';

	return 0;
}
