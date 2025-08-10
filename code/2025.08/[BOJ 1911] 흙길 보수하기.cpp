#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Pool {
    int s, e;
};

int n, l;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = 0;
    cin >> n >> l;

    vector<Pool> poolList(n);
    for (int i = 0; i < n; ++i) {
        cin >> poolList[i].s >> poolList[i].e;
    }
    sort(poolList.begin(), poolList.end(), [](const Pool& a, const Pool& b) {
        return a.s < b.s;
        }
    );

    int prev = -1;
    for (const auto& a : poolList) {
        int start = (prev > a.s) ? prev : a.s;

        if (start >= a.e) continue;

        float poolLen = a.e - start;
        int panelNum = ceil(poolLen / l);

        ans += panelNum;
        prev = start + panelNum * l;
    }

    cout << ans << '\n';

    return 0;
}
