#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int calcTimeGap(const string& start, const string& end) {
	int startM, startS, endM, endS;

	startM = ((start[0] - '0') * 10) + (start[1] - '0');
	startS = ((start[3] - '0') * 10) + (start[4] - '0');

	endM = ((end[0] - '0') * 10) + (end[1] - '0');
	endS = ((end[3] - '0') * 10) + (end[4] - '0');

	return (endM * 60 + endS) - (startM * 60 + startS);
}

void printTime(int totalMin) {
	int m = totalMin / 60;
	int s = totalMin % 60;

	string min;
	string sec;

	min += to_string(m / 10);
	sec += to_string(s / 10);
	min += to_string(m % 10);
	sec += to_string(s % 10);

	cout << min << ":" << sec << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int ans[2] = { 0, 0 };
	int goal[2] = { 0, 0 };
	string winningStartTime;

	int goalTeam;
	string time;
	for (int i = 0; i < n; ++i) {
		cin >> goalTeam >> time;

		if (!winningStartTime.empty()) {
			if (goal[0] > goal[1]) {
				ans[0] += calcTimeGap(winningStartTime, time);
				winningStartTime = time;
			}
			else if (goal[1] > goal[0]) {
				ans[1] += calcTimeGap(winningStartTime, time);
				winningStartTime = time;
			}
		}

		++goal[goalTeam - 1];

		if (goal[0] != goal[1] && winningStartTime.empty()) {
			winningStartTime = time;
		}
		else if (goal[0] == goal[1]) {
			winningStartTime.clear();
		}
	}

	if (goal[0] > goal[1]) {
		ans[0] += calcTimeGap(time, "48:00");
	}
	else if (goal[1] > goal[0]) {
		ans[1] += calcTimeGap(time, "48:00");
	}

	printTime(ans[0]);
	printTime(ans[1]);

	return 0;
}
