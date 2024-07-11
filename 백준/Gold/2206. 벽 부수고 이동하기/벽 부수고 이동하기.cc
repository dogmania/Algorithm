#include <bits/stdc++.h>

using namespace std;

int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int bfs(vector<vector<int>>& graph, vector<vector<vector<bool>>>& visited) {
    deque<tuple<int, int, int, bool>> dq;   // x, y, answer, canBreak
    dq.push_back({0, 0, 1, true});

    while(!dq.empty()) {
        tuple<int, int, int, bool> currentNode = dq.front();
        dq.pop_front();

        int x = get<0>(currentNode);
        int y = get<1>(currentNode);
        int count = get<2>(currentNode);
        int canBreak = get<3>(currentNode);

        if (x == m - 1 && y == n - 1) return count;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < m && nx >= 0 && ny < n && ny >= 0) {
                if (graph[ny][nx] == 1 && canBreak && !visited[ny][nx][0]) {
                    dq.push_back({nx, ny, count + 1, false});
                    visited[ny][nx][0] = true;
                } else if (graph[ny][nx] == 0 && !visited[ny][nx][canBreak]) {
                    dq.push_back({nx, ny, count + 1, canBreak});
                    visited[ny][nx][canBreak] = true;
                }
            }
        }
    }

    return -1;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(m, 0));
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(2, false)));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++) {
            graph[i][j] = s[j] - '0';
        }
    }

    visited[0][0][1] = true;
    int answer = bfs(graph, visited);

    cout << answer << '\n';
}