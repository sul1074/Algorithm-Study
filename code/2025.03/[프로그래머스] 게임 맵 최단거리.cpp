#include <vector>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> Pos;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool isIn(Pos size, int x, int y) {
    return x >= 0 && x < size.first 
        && y >= 0 && y < size.second;
}

int bfs(vector<vector<int>> maps, Pos start) {
    Pos size = make_pair(maps.size(), maps[0].size());
    queue<Pos> q;
    q.push(start);
    
    while (!q.empty()) {
        Pos curr = q.front(); q.pop();
            
        for (int i = 0; i < 4; ++i) {
            int nextX = curr.first + dx[i];
            int nextY = curr.second + dy[i];
            
            if (!isIn(size, nextX, nextY) || maps[nextX][nextY] != 1) continue;
            
            maps[nextX][nextY] += maps[curr.first][curr.second];
            
            if (nextX == size.first - 1 && nextY == size.second - 1) 
                return maps[nextX][nextY];
            
            q.push(make_pair(nextX, nextY));
        }
    }
    
    return -1;
}

int solution(vector<vector<int>> maps)
{
    int answer = bfs(maps, make_pair(0, 0));
    
    return answer;
}
