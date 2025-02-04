#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> info(31, 0);
    int answer = 0;
    
    for (auto r : reserve) info[r] += 1;
    for (auto l : lost) info[l] -= 1;
    
    for (int i = 1; i <= n; ++i) {
        if (info[i] == -1) {
            if (info[i - 1] == 1) {
                info[i - 1] = info[i] = 0;
            }
            else if (info[i + 1] == 1) {
                info[i + 1] = info[i] = 0;
            }
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        if (info[i] >= 0) answer++;
    }
    
    return answer;
}
