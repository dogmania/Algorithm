#include <bits/stdc++.h>

using namespace std;

int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs(vector<vector<int>> graph, int x1, int y1, int x2, int y2) {
    int day = 0;
    deque<pair<int, int>> dq;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    graph[y1][x1] = 2;
    graph[y2][x2] = 2;
    visited[y1][x1] = true;
    visited[y2][x2] = true;

    while(1) {
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (graph[i][j] == 1) count++;
            }
        }

        if (count == 0) break;

        day++;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (graph[i][j] == 2) {
                    for (int k = 0; k < 4; k++) {
                        int nx = j + dx[k];
                        int ny = i + dy[k];

                        if (nx >= 0 && nx < m && ny >= 0 && ny < n && graph[ny][nx] != 2 && !visited[ny][nx]) {
                            visited[ny][nx] = true;
                            dq.push_back({nx, ny});
                        }
                    }
                }
            }
        }

        while(!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            graph[y][x] = 2;
        }
    }

    return day;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vector<pair<int, int>> emptySpace;
    int answer = 1e9;

    vector<vector<int>> graph(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++) {
            graph[i][j] = s[j] - '0';

            if (s[j] == '0') emptySpace.push_back({j, i});
        }   
    }

    int size = emptySpace.size();
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            int result = bfs(graph, emptySpace[i].first, emptySpace[i].second, emptySpace[j].first, emptySpace[j].second);
            answer = min(answer, result);
        }
    }

    cout << answer << '\n';
}