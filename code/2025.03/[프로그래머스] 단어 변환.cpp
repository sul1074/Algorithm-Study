#include <string>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

bool isVaild(string w1, string w2) {
    int cnt = 0;
    
    for (int i = 0; i < w1.length(); ++i) {
        if (w1[i] != w2[i]) ++cnt;
        
        if (cnt > 1) return false;
    }
    
    return true;
}

int bfs(string begin, string target, const vector<string>& words) {
    unordered_set<string> visited;
    queue<pair<string, int>> q;
    
    q.push(make_pair(begin, 0)); 
    while (!q.empty()) {
        string currWord = q.front().first;
        int cnt = q.front().second;
        
        if (currWord == target) return cnt;
        
        q.pop();
        
        for (auto w : words) {
            if (!visited.count(w) && isVaild(currWord, w)) {
                visited.insert(w);
                q.push(make_pair(w, cnt + 1));
            }
        }
    }
    
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = bfs(begin, target, words); 
    
    return answer;
}
