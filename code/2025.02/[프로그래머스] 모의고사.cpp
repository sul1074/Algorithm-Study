#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {   
    vector<int> answer(3, 0);
    vector<vector<int>> poolMath;
    
    poolMath.push_back({1, 2, 3, 4, 5});
    poolMath.push_back({2, 1, 2, 3, 2, 4, 2, 5});
    poolMath.push_back({3, 3, 1, 1, 2, 2, 4, 4, 5, 5});
    
    for (int i = 0; i < answers.size(); ++i) {
        if (poolMath[0][i % poolMath[0].size()] == answers[i]) answer[0]++;
        if (poolMath[1][i % poolMath[1].size()] == answers[i]) answer[1]++;
        if (poolMath[2][i % poolMath[2].size()] == answers[i]) answer[2]++;
    }
    
    int maxCorr = max(answer[0], max(answer[1], answer[2]));
    vector<int> rst;
                      
    for (int i = 0; i < 3; ++i) {
        if (answer[i] == maxCorr) rst.push_back(i + 1);
    }
    
    return rst;
}
