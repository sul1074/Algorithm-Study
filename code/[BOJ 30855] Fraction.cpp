#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> Fraction;

int GCD(int n1, int n2) {
	if (n2 == 0) return n1;
	return GCD(n2, n1 % n2);
}

Fraction simplify(int num, int den) {
	int gcd = GCD(num, den);
	num /= gcd;
	den /= gcd;

	return { num, den };
}

Fraction add(Fraction a, Fraction b) {
	return simplify(a.first * b.second + b.first * a.second, a.second * b.second);
}

Fraction divide(Fraction a, Fraction b) {
	return simplify(a.first * b.second, a.second * b.first);
}

void debug(const Fraction& f) {
	cout << f.first << '/' << f.second << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	/*
	* symbols 내에서 index 접근으로만 a, b, c 계산을 하기에는 부적절하다고 느낌.
	* 계산 결과인 fraction을 char 자료형으로 변환할 수 없었기 때문.
	* 그래서 fraction 형을 따로 관리할 수 있는 스택을 별도로 생성.
	* -> 기존 컨테이너 내에서 풀이가 힘들거 같으면, 별도의 관리 컨테이너를 만들어라
	*/
	stack<Fraction> fractionStack;
	stack<char> parenthesesStack;
	vector<char> symbols(n, '\0');

	for (int i = 0; i < n; ++i) {
		cin >> symbols[i];
	}

	for (int i = n - 1; i > -1; --i) {
		char symbol = symbols[i];

		if (symbol == ')') {
			parenthesesStack.push(symbol);
		}
		else if (symbol == '(') {
			if (parenthesesStack.empty() || fractionStack.size() < 3) {
				cout << -1 << '\n';
				exit(0);
			}

			Fraction a = fractionStack.top(); fractionStack.pop();
			Fraction b = fractionStack.top(); fractionStack.pop();
			Fraction c = fractionStack.top(); fractionStack.pop();
			Fraction rst = add(a, divide(b, c));

			fractionStack.push(rst);
			parenthesesStack.pop();
		}
		else {
			fractionStack.push({ symbol - '0', 1 });
		}
	}

	Fraction ans = fractionStack.top(); fractionStack.pop();

	if (!parenthesesStack.empty() || !fractionStack.empty()) {
		cout << -1 << '\n';
	}
	else {
		cout << ans.first << ' ' << ans.second << '\n';
	}

	return 0;
}