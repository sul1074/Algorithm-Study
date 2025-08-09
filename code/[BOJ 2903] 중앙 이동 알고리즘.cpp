#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int first = 3, ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = first * (first);
        first = 2 * first - 1;
    }

    cout << ans << '\n';

    return 0;
}
