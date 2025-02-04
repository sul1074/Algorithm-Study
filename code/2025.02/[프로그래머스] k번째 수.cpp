#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (auto com : commands) {
        int i = com[0] - 1;
        int j = com[1];
        int k = com[2] - 1;
        
        vector<int> temp(array.begin() + i, array.begin() + j);
        
        sort(temp.begin(), temp.end());        
        answer.push_back(temp[k]);
    }  
    
    return answer;
}
