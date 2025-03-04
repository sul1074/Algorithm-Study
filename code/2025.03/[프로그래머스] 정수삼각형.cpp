#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> dp(triangle.size());
    dp[0].push_back(triangle[0][0]);
    
    for (int i = 1; i < triangle.size(); ++i) {
        for (int j = 0; j < triangle[i].size(); ++j) {
            if (j == 0) 
                dp[i].push_back(dp[i - 1][j] + triangle[i][j]);
            else if (j == triangle[i].size() - 1)
                dp[i].push_back(dp[i - 1][j - 1] + triangle[i][j]);
            else 
                dp[i].push_back(triangle[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]));
        }
    }

    int answer = *max_element(dp[triangle.size() - 1].begin(), dp[triangle.size() - 1].end());
    return answer;
}
