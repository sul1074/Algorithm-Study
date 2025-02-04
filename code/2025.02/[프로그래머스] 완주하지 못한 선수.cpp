#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> m;
    
    for (const auto& p : participant) {
        m[p]++;
    }
    
    for (const auto& com : completion) {
        m[com]--; 
    }
    
    for (const auto& info : m) {
        if (info.second > 0) {
            answer += info.first;
            break;
        }
    }
    
    return answer;
}
