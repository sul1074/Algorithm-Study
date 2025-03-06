#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int accum = 0;
    
    for (int i = 0; i < progresses.size(); ++i) {
        int currP = progresses[i] + (speeds[i] * accum);
        
        if (currP >= 100) {
            answer.back()++;
        }
        else {
            // 실수형으로 계산해야, 제대로 연산이 됨
            accum += ceil((100.0f - currP) / speeds[i]);
            answer.push_back(1);
        }
    }
    
    return answer;
}
