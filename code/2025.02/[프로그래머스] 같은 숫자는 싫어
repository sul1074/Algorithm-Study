#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> s;

    for (auto i : arr) {
        if (s.empty()) {
            s.push(i);
            answer.push_back(i);
            continue;
        }
        
        if (s.top() == i) continue;
        
        s.push(i);
        answer.push_back(i);
    }
    
    return answer;
}
