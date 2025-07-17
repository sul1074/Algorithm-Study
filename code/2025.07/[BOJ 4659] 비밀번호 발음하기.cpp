#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isVowel(char c) {
	return c == 'a' ||
		c == 'e' ||
		c == 'i' ||
		c == 'o' ||
		c == 'u';
}

bool con1(const string& input) {
	return input.find('a') != string::npos ||
		input.find('e') != string::npos ||
		input.find('i') != string::npos ||
		input.find('o') != string::npos ||
		input.find('u') != string::npos;
}

bool con2(const string& input) {
	char prev = input.front();
	int cons = 1;

	for (auto ch = input.begin() + 1; ch != input.end(); ++ch) {
		if (isVowel(prev) && isVowel(*ch)) {
			++cons;
		}
		else if (!isVowel(prev) && !isVowel(*ch)) {
			++cons;
		}
		else {
			cons = 1;
			prev = *ch;
		}

		if (cons >= 3) {
			return false;
		}
	}

	return true;
}

bool con3(const string& input) {
	char prev = input.front();

	for (auto ch = input.begin() + 1; ch != input.end(); ++ch) {
		if (*ch == prev) {
			if (prev != 'e' && prev != 'o') return false;
		}
		else {
			prev = *ch;
		}
	}

	return true;
}

void sol(const string& input) {
	if (!con1(input) || !con2(input) || !con3(input)) {
		cout << '<' << input << '>' << " is not acceptable." << '\n';
	}
	else {
		cout << '<' << input << '>' << " is acceptable." << '\n';
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string input;
	while (1) {
		cin >> input;

		if (input == "end") break;

		sol(input);
	}

	return 0;
}
