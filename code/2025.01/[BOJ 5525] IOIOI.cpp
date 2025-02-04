#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::string;

int main(void) {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, cnt = 0;
	cin >> n >> m;
	string s;
	cin >> s;

	int prevCorrectnessCnt = 1;
	for (int i = 0; i < m; i++) {
		// I를 발견하면 Pn 탐색 시작
		if (s[i] == 'I') {
			int correctnessCnt = prevCorrectnessCnt;

			for (int j = i + 1; j < m; j++) {
				// 같은 문자가 연속하면 아니므로 탐색을 종료
				if (s[j] == s[j - 1]) {
					// 이때까지 탐색한 문자열은 Pn이 될 가능성이 없으므로, j부터 탐색하도록
					prevCorrectnessCnt = 1;
					i = j - 1;
					break;
				}

				correctnessCnt++;

				// Pn을 찾았고, 다음에는 P(n-1) 부분부터 탐색 시작
				if (correctnessCnt == 2 * n + 1) {
					cnt++;
					i = j - 1;
					break;
				}

				// 연산 횟수를 줄이기 위해, Pn의 일부를 찾은 곳부터 연산할 수 있도록
				if (s[j] == 'I') {
					i = j - 1;
					prevCorrectnessCnt = correctnessCnt;
				}
			}
		}
	}

	cout << cnt;

	return 0;
}