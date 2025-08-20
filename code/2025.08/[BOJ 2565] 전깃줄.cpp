#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ElecWire {
	int s, e;
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<ElecWire> wires(n);
	for (int i = 0; i < n; ++i) {
		cin >> wires[i].s >> wires[i].e;
	}
	sort(wires.begin(), wires.end(), [](const ElecWire& a, const ElecWire& b) {
		return a.s < b.s;
	});

	int lis = 0;
	vector<int> dp(n, 1);
	for (int i = 0; i < n; ++i) {
		int e = wires[i].e;
		for (int j = 0; j < i; ++j) {
			if (e > wires[j].e) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
		lis = max(lis, dp[i]);
	}

	cout << n - lis << '\n';

	return 0;
}

/*
* 시작점이 작은데 끝점은 더 큰 경우
* 시작점이 큰데 끝점은 더 작은 경우
* -> 겹친다
* 즉, 계속해서 시작점과 끝점이 증가해야 한다
* 전체 전깃줄 갯수 - 가장 긴 증가하는 끝점 수열의 길이 = 제거한 최소 전깃줄 갯수
*/
