#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int video[64][64];
int n;

struct Pos {
	int r;
	int c;
};

int checkSector(Pos leftTop, Pos rightBottom) {
	int first = video[leftTop.r][leftTop.c];

	for (int i = leftTop.r; i < rightBottom.r; ++i) {
		for (int j = leftTop.c; j < rightBottom.c; ++j) {
			if (first != video[i][j]) return -1;
		}
	}

	return first;
}

void divAndCon(Pos leftTop, Pos rightBottom) {
	int rst = checkSector(leftTop, rightBottom);
	if (rst >= 0) {
		cout << rst;
		return;
	}

	int mid_r = (leftTop.r + rightBottom.r) / 2;
	int mid_c = (leftTop.c + rightBottom.c) / 2;

	// 왼쪽 위
	Pos leftTopLT = { leftTop.r, leftTop.c };
	Pos leftTopRB = { mid_r, mid_c };

	// 오른쪽 위
	Pos rightTopLT = { leftTop.r, mid_c };
	Pos rightTopRB = { mid_r, rightBottom.c };

	// 왼쪽 아래
	Pos leftBottomLT = { mid_r, leftTop.c };
	Pos leftBottomRB = { rightBottom.r, mid_c };

	// 오른쪽 아래
	Pos rightBottomLT = { mid_r, mid_c };
	Pos rightBottomRB = { rightBottom.r, rightBottom.c };

	cout << '(';
	divAndCon(leftTopLT, leftTopRB);
	divAndCon(rightTopLT, rightTopRB);
	divAndCon(leftBottomLT, leftBottomRB);
	divAndCon(rightBottomLT, rightBottomRB);
	cout << ')';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string line;
		cin >> line;

		for (int j = 0; j < n; ++j) {
			video[i][j] = line[j] - '0';
		}
	}

	divAndCon({ 0, 0 }, { n, n });

	return 0;
}
