#include <vector>
#include <queue>
#include <functional>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> q(scoville.begin(), scoville.end());
    int cnt = 0;
    
    while (q.size() > 1) {
        int least = q.top(); q.pop();
        
        if (least >= K) return cnt;
        
        int secondLeast = q.top(); q.pop();
        int k = least + secondLeast * 2;
        
        q.push(k);
        cnt++;
    }

    return (q.top() >= K) ? cnt : -1;
}
