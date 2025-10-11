#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

bool canProcessDungeon(const vector<tuple<int, int, int>>& rooms, 
	long long maxHp, int initAtk) {
	long long warriorHp = maxHp, warriorAtk = initAtk;
	
	for (const auto& room : rooms) {
		int type, atk, health;
		tie(type, atk, health) = room;

		if (type == 1) {
			long long damagedCnt = health / warriorAtk;
			if (health % warriorAtk == 0) --damagedCnt;

			warriorHp -= damagedCnt * atk;
		}
		else {
			warriorHp = min(warriorHp + health, maxHp);
			warriorAtk += atk;
		}

		if (warriorHp <= 0) return false;
	}

	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int roomNum, initAtk;
	cin >> roomNum >> initAtk;

	vector<tuple<int, int, int>> rooms(roomNum);
	for (int i = 0; i < roomNum; ++i) {
		int t, a, h;
		cin >> t >> a >> h;
		rooms[i] = make_tuple(t, a, h);
	}

	long long left = 1, right = LLONG_MAX - 1, maxHp = LLONG_MAX;
	while (left <= right) {
		long long mid = (left + right) / 2;

		if (canProcessDungeon(rooms, mid, initAtk)) {
			right = mid - 1;
			maxHp = mid;
		}
		else {
			left = mid + 1;
		}
	}

	cout << maxHp << '\n';

	return 0;
}
