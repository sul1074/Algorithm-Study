#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    
    cout << min({x, y, w - x, h - y}) << '\n';
    
    return 0;
}
