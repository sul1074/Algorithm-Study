#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

int n;
int ans = INT_MIN;
int maxParenthes;
string num;
string op;

int calc() {
	int rst = num[0] - '0';
	for (int i = 0; i < op.size(); ++i) {
		switch (op[i]) {
		case '+':
			rst += (num[i + 1] - '0');
			break;
		case '-':
			rst -= (num[i + 1] - '0');
			break;
		case '*':
			rst *= (num[i + 1] - '0');
			break;
		}
	}

	return rst;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	char ch;
	for (int i = 0; i < n; ++i) {
		cin >> ch;
		if (isdigit(ch)) num += ch;
		else op += ch;
	}
	maxParenthes = num.size() / 2;

	cout << calc() << '\n';

	return 0;
}

/*
* 괄호 안에는 하나의 연산자만 가능. 즉, 하나의 연산
* 중첩 괄호 사용 불가
*/