#include<vector>
#include<deque>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(vector<vector<int>> maps, int x, int y) {
    deque<pair<int, int>> dq;
    int n = maps.size();
    int m = maps[0].size();
    
    dq.push_back({x, y});
    
    while (!dq.empty()) {
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
            if (maps[nx][ny] == 0) continue;
            else if (maps[nx][ny] == 1) {
                dq.push_back({nx, ny});
                maps[nx][ny] = maps[x][y] + 1;
            }
        }
    }
    
    if (maps[n - 1][m - 1] == 1) return -1;
    else return maps[n - 1][m - 1];
}

int solution(vector<vector<int>> maps)
{
    return bfs(maps, 0, 0);
}