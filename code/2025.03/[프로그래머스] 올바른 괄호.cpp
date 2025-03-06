#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    if (s.length() <= 1) return false;
    
    stack<char> q;
    
    for (char ch : s) {
        if (ch == '(') 
            q.push(ch);
        else {
            if (q.empty() || q.top() == ')') return false;
            
            q.pop();
        }
    }

    return (q.size() > 0) ? false : true;
}
