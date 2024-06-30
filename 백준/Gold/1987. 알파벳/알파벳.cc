#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void dfs(vector<vector<char>>& graph, vector<vector<bool>>& visited, tuple<int, int, int> start, int x, int y, map<char, int>& mp, int& answer) {
    int c_x = get<0>(start);
    int c_y = get<1>(start);
    int current_count = get<2>(start);

    visited[c_y][c_x] = true;

    for (int i = 0; i < 4; i++) {
        int nx = c_x + dx[i];
        int ny = c_y + dy[i];

        if (nx >= 0 && nx < x && ny >= 0 && ny < y && !visited[ny][nx] && mp[graph[ny][nx]] == 0) {
            mp[graph[ny][nx]] = 1;
            visited[ny][nx] = true;
            dfs(graph, visited, {nx, ny, current_count + 1}, x, y, mp, answer);
            //아래 코드는 나머지 방향에 대해서도 재귀적으로 탐색하기 위해 이전 상태로 되돌리는 작업
            visited[ny][nx] = false;    
            mp[graph[ny][nx]] = 0;  
        }
    }

    if (current_count > answer) answer = current_count;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m; //n이 세로, m이 가로
    cin >> n >> m;

    vector<vector<char>> graph(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int answer = 0;
    map<char, int> mp;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++) {
            graph[i][j] = s[j];
            mp[s[j]] = 0;
        }
    }

    mp[graph[0][0]] = 1;

    dfs(graph, visited, {0, 0, 1}, m, n, mp, answer);   // 파라미터로 전달하는 tuple -> {시작 x, 시작 y, 이동한 칸의 개수}

    cout << answer << '\n';
}