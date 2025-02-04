#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

int bfs(int start, vector<bool>& visited, const vector<vector<int>>& graph) {
    int cnt = 0;
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front(); q.pop();

        for (int neighbor : graph[node]) {
            if (visited[neighbor]) continue;

            q.push(neighbor);
            visited[neighbor] = true;
            cnt++;
        }
    }

    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 214700000;

    for (int t = 0; t < n - 1; t++) {
        vector<bool> visited(n + 1, false);
        vector<vector<int>> graph(n + 1);

        for (int i = 0; i < n - 1; i++) {
            if (i == t) continue;

            int w1 = wires[i][0];
            int w2 = wires[i][1];

            graph[w1].push_back(w2);
            graph[w2].push_back(w1);
        }

        vector<int> resList;
        for (int i = 1; i <= n; i++) {
            if (visited[i]) continue;

            cout << "방문한 노드: " << i;

            resList.push_back(bfs(i, visited, graph));
        }

        // 입력이 어차피 두 번의 bfs 탐색만 이루어지도록 들어옴.
        int temp = abs(resList[0] - resList[1]);
        answer = (temp < answer) ? temp : answer;
    }


    return answer;
}