#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	bool isPromising = true;
	int idx = 0;
	while (idx < str.size()) {
		string pika = str.substr(idx, 2);
		string chu = str.substr(idx, 3);

		if (pika == "pi" || pika == "ka") idx += 2;
		else if (chu == "chu") idx += 3;
		else {
			isPromising = false;
			break;
		}
	}

	if (isPromising) cout << "YES" << '\n';
	else cout << "NO" << '\n';

	return 0;
}
