#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        int total_blocks = n * (n + 1) / 2;
        cout << total_blocks << endl;
    }
    return 0;
}
