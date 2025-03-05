#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

int solution(int N, int number) {
    vector<unordered_set<int>> dp(9);
    
    dp[0].insert(0);
    int base = 0;
    for (int i = 1; i < 9; ++i) {
        base = 10 * base + N;
        dp[i].insert(base); 
    }
    
    for (int i = 2; i < 9; ++i) {
        for (int j = 1; j < i; ++j) {
            for (int n1 : dp[j]) {
                for (int n2 : dp[i - j]) {
                    dp[i].insert(n1 + n2);
                    if (n2 != 0) dp[i].insert(int(n1 / n2));
                    dp[i].insert(n1 * n2);
                    if (n1 >= n2) dp[i].insert(n1 - n2);
                }
            }
        }
        
        for (int k = 1; k < 9; ++k) {
            if (dp[k].find(number) != dp[k].end()) return k;
        }
    }
    
    return -1;
}
