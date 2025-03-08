#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

bool isPrime(int n) {
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    
    return true;
}

void dfs(unordered_set<int>& numSet, const vector<int>& numList, vector<bool>& visited, 
         int num, int depth, int goalDepth) {   
    if (depth == goalDepth) {
        numSet.insert(num);
        return;
    }
    
    for (int i = 0; i < numList.size(); ++i) {
        if (visited[i]) continue;
        
        visited[i] = true;    
        dfs(numSet, numList, visited, num * 10 + numList[i], depth + 1, goalDepth);      
        visited[i] = false;
    }
}

int solution(string numbers) {
    unordered_set<int> numSet;
    vector<int> numList;
    vector<bool> visited(numbers.length(), false);
    int answer = 0;
    
    // dfs에 숫자 배열로 넘길거라, 숫자로 변환해서 추가
    for (char ch : numbers) {
        numList.push_back(ch - '0');
    }
    
    // 1~N자리 수 조합 만들어서 set에 추가
    for (int i = 1; i <= numList.size(); ++i) {
        dfs(numSet, numList, visited, 0, 0, i);
    }
    
    for (auto n : numSet) {
        if (isPrime(n)) ++answer;
    }
        
    return answer;
}
