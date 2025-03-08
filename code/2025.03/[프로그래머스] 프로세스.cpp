#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    int answer = 0;
    
    for (int i = 0; i < priorities.size(); ++i) {
        q.push(make_pair(priorities[i], i));
        pq.push(priorities[i]);
    }
    
    while (!q.empty()) {
        auto n = q.front(); q.pop();
        int nPrio = n.first;
        int nLoc = n.second;
        
        // 우선순위가 더 높은 프로세스가 존재
        if (pq.top() > nPrio) q.push(n);
        
        // 해당 프로세스 실행 가능
        else {
            pq.pop();
            ++answer;
            
            if (nLoc == location) return answer;
        }
    }
    
    return answer;
}
