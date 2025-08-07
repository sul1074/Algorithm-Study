#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

int t;

string rotateClockwise(const string& gear) {
	string rst = gear;
	char temp = gear.back();

	rst.pop_back();
	rst.insert(rst.begin(), temp);

	return rst;
}

string rotateCounterClockwise(const string& gear) {
	string rst = gear;
	char temp = gear.front();

	rst.erase(rst.begin());
	rst.push_back(temp);

	return rst;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	vector<string> gear(t + 1);
	for (int i = 1; i <= t; ++i) {
		cin >> gear[i]; // 12시 방향부터 시계 순으로
	}
	
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int gNum, dir;
		cin >> gNum >> dir;

		vector<string> temp(gear.begin(), gear.end());

		if (dir == 1) temp[gNum] = rotateClockwise(gear[gNum]);
		else if (dir == -1) temp[gNum] = rotateCounterClockwise(gear[gNum]);

		int prev = dir;
		for (int i = gNum - 1; i > 0; --i) {
			if (gear[i][2] == gear[i + 1][6]) break;

			if (prev == 1) {
				temp[i] = rotateCounterClockwise(gear[i]);
				prev = -1;
			}
			else if (prev == -1) {
				temp[i] = rotateClockwise(gear[i]);
				prev = 1;
			}
		}

		prev = dir;
		for (int i = gNum + 1; i <= t; ++i) {
			if (gear[i][6] == gear[i - 1][2]) break;

			if (prev == 1) {
				temp[i] = rotateCounterClockwise(gear[i]);
				prev = -1;
			}
			else if (prev == -1) {
				temp[i] = rotateClockwise(gear[i]);
				prev = 1;
			}
		}

		gear = temp;
	}

	int cnt = 0;
	for (int i = 1; i <= t; ++i) {
		if (gear[i].front() == '1') ++cnt;
	}

	cout << cnt << '\n';

	return 0;
}

/*
* N극이 0, S극이 1
* 시계는 1, 반시계는 -1
* idx 0 이 12시방향 톱니, 2는 3시, 4는 6시, 6은 9시
*/
