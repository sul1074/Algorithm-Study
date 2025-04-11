#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string channel[100];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string ans = "";
	int n, idxKBS1, idxKBS2;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> channel[i];

		if (channel[i] == "KBS1") idxKBS1 = i;
		else if (channel[i] == "KBS2") idxKBS2 = i;
	}

	int point = 0;
	while (channel[point] != "KBS1") {
		ans += "1";
		++point;
	}

	while (channel[0] != "KBS1") {
		string temp = channel[point];
		channel[point] = channel[point - 1];
		channel[point - 1] = temp;

		ans += "4";
		--point;
	}

	while (channel[point] != "KBS2") {
		ans += "1";
		++point;
	}

	while (channel[1] != "KBS2") {
		string temp = channel[point];
		channel[point] = channel[point - 1];
		channel[point - 1] = temp;

		ans += "4";
		--point;
	}

	cout << ans;

	return 0;
}
