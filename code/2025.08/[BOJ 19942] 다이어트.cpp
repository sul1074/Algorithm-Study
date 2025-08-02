#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct info {
	int p, f, s, v, c;
};

int n, ans = INT_MAX;
int opt[4];
vector<info> ingredients(16);
vector<int> ansIngredients;

info calc(const vector<int>& tempIng) {
	info rst;
	rst.p = 0; rst.f = 0; rst.s = 0; rst.v = 0;

	for (auto ing : tempIng) {
		rst.p += ingredients[ing].p;
		rst.f += ingredients[ing].f;
		rst.s += ingredients[ing].s;
		rst.v += ingredients[ing].v;
	}

	return rst;
}

bool isValid(const info& in) {
	return in.p >= opt[0] && in.f >= opt[1] &&
		in.s >= opt[2] && in.v >= opt[3];
}

void backtracking(vector<int>& tempIng, int price, int start) {
	if (price >= ans) return;

	if (isValid(calc(tempIng))) {
		ans = price;
		ansIngredients = tempIng;
	}

	for (int i = start; i <= n; ++i) {
		tempIng.push_back(i);
		backtracking(tempIng, price + ingredients[i].c, i + 1);
		tempIng.pop_back();
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	
	for (int i = 0; i < 4; ++i) {
		cin >> opt[i];
	}

	for (int i = 1; i <= n; ++i) {
		cin >> ingredients[i].p		// 단백질
			>> ingredients[i].f		// 지방
			>> ingredients[i].s		// 탄수화물
			>> ingredients[i].v		// 비타민
			>> ingredients[i].c;	// 비용
	}

	vector<int> tempIng;
	backtracking(tempIng, 0, 1);
	if (ans == INT_MAX) ans = -1;

	cout << ans << '\n';
	for (auto ing : ansIngredients) cout << ing << ' ';
	cout << '\n';

	return 0;
}
