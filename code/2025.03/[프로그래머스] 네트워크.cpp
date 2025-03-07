#include <vector>
#include <iostream>

using namespace std;

void dfs(int node, const vector<vector<int>>& com, vector<bool>& visited) {
    visited[node] = 1;
    
    for (int i = 0; i < com[node].size(); ++i) {
        if (visited[i]) continue;
        
        if (com[node][i] == 1) {
            visited[i] = true;
            
            dfs(i, com, visited);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    
    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;
        
        dfs(i, computers, visited);
        ++answer;
    }
        
    return answer;
}
