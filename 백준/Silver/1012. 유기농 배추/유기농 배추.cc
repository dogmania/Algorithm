#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>> graph, vector<vector<bool>>& visited, int y, int x, int m, int n) {
    deque<tuple<int, int>> dq;

    visited[y][x] = true;
    dq.push_back({x, y});

    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    while(!dq.empty()) {
        tuple<int, int> ft = dq.front();
        dq.pop_front();
        
        for (int i = 0; i < 4; i++) {
            int nx = get<0>(ft) + dx[i];
            int ny = get<1>(ft) + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (graph[ny][nx] == 1 && !visited[ny][nx]) {
                    dq.push_back({nx, ny});
                    visited[ny][nx] = true;
                }
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    vector<int> answer;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int m, n, count;
        int ans = 0;
        cin >> m >> n >> count;
        vector<vector<int>> graph(n, vector<int>(m, 0));
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int j = 0; j < count; j++) {
            int x, y;
            cin >> x >> y;

            graph[y][x] = 1;
        }

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (graph[j][k] == 1 && !visited[j][k]) {
                    bfs(graph, visited, j, k, m, n);
                    ans++;
                }
            }
        }

        answer.push_back(ans);
    }

    for (auto ans: answer) {
        cout << ans << '\n';
    }
}