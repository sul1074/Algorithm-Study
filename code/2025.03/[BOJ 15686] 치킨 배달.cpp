#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<int, int> Pos;

void backtracking(vector<vector<int>>& permutationList, vector<int>& curr, int num, int m, int start) {
	if (curr.size() == m) {
		permutationList.push_back(curr);
		return;
	}

	for (int i = start; i < num; ++i) {
		curr.push_back(i);
		backtracking(permutationList, curr, num, m, i + 1);
		curr.pop_back();
	}
}

int distance(Pos p1, Pos p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int solution(const vector<Pos>& homeList, const vector<Pos>& chickenList, const vector<vector<int>>& remainChicken) {
	int sum = 2147000000;
	
	for (auto permutationList : remainChicken) {
		int tempSum = 0;

		for (Pos homeP : homeList) {
			int temp = 2147000000;
			
			for (int i : permutationList) {
				temp = min(temp, distance(homeP, chickenList[i]));
			}
			tempSum += temp;
		}

		sum = min(sum, tempSum);
	}

	return sum;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, ans = 0;
	cin >> n >> m;

	vector<Pos> homeList;
	vector<Pos> chickenList;
	vector<vector<int>> permutationList;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int info;
			cin >> info;

			if (info == 1) homeList.push_back(make_pair(i, j));
			else if (info == 2) chickenList.push_back(make_pair(i, j));
		}
	}

	vector<int> curr;
	backtracking(permutationList, curr, chickenList.size(), m, 0);

	ans = solution(homeList, chickenList, permutationList);

	cout << ans << '\n';

	return 0;
}
