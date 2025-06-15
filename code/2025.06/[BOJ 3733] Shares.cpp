#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    long long S;

    while (std::cin >> N >> S) {
        std::cout << S / (N + 1) << '\n';
    }

    return 0;
}
