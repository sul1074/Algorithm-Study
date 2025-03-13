#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> m;
    
    for (auto cloth : clothes) {    
        string type = cloth[1];
        m[type]++;
    }
    
    for (auto cm : m) {
        answer *= (cm.second + 1);
    }
    
    return answer - 1;
}
