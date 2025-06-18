#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, target;
    cin >> n >> target;

    vector<vector<int>> map(n, vector<int>(n, 0));
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    int dx[] = { 1, 0, -1, 0 };
    int dy[] = { 0, 1, 0, -1 };

    int dir = 0;
    int cnt = n * n;
    int i = 0, j = 0;
    int ti = -1, tj = -1;

    while (cnt > 0) {
        if (cnt == target) {
            ti = i + 1;
            tj = j + 1;
        }

        map[i][j] = cnt;
        visited[i][j] = true;
        cnt--;

        int ni = i + dx[dir];
        int nj = j + dy[dir];

        if (ni < 0 || ni >= n || nj < 0 || nj >= n || visited[ni][nj]) {
            dir = (dir + 1) % 4;
        }

        i += dx[dir];
        j += dy[dir];
    }

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cout << map[row][col] << " ";
        }
        cout << '\n';
    }

    cout << ti << ' ' << tj << '\n';

    return 0;
}
