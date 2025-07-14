#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[2] = { 1, -1 };

bool isIn(int size, int bracketPos, int bracketSize) {
    return bracketPos >= 1 && bracketPos + bracketSize - 1 <= size;
}

bool canCollect(int applePos, int bracketPos, int bracketSize) {
    return bracketPos <= applePos && bracketPos + bracketSize - 1 >= applePos;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int screenSize, bracketSize;
    cin >> screenSize >> bracketSize;

    int appleNum;
    cin >> appleNum;

    vector<int> applesPos(appleNum);
    for (int i = 0; i < appleNum; ++i) {
        cin >> applesPos[i];
    }

    int ans = 0, bracketPos = 1;

    for (int pos : applesPos) {
        if (canCollect(pos, bracketPos, bracketSize)) continue;

        vector<bool> visited(screenSize + 2, false);
        queue<pair<int, int>> q;

        q.push({ bracketPos, 0 });
        visited[bracketPos] = true;

        while (!q.empty()) {
            int curr, depth;
            tie(curr, depth) = q.front(); q.pop();

            if (canCollect(pos, curr, bracketSize)) {
                ans += depth;
                bracketPos = curr;

                break;
            }

            for (int i = 0; i < 2; ++i) {
                int next = curr + dx[i];

                if (isIn(screenSize, next, bracketSize) && !visited[next]) {
                    visited[next] = true;
                    q.push({ next, depth + 1 });
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
