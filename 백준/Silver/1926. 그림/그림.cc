#include <bits/stdc++.h>

using namespace std;

int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void bfs(vector<vector<int>>& graph, vector<vector<bool>>& visited, vector<int>& area, int x, int y) {
    deque<tuple<int, int>> dq;
    int currentArea = 0;

    visited[y][x] = true;
    dq.push_back({x, y});

    while(!dq.empty()) {
        tuple<int, int> currentNode = dq.front();
        dq.pop_front();

        int currentX = get<0>(currentNode);
        int currentY = get<1>(currentNode);
        currentArea++;

        for (int i = 0; i < 4; i++) {
            int nx = currentX + dx[i];
            int ny = currentY + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[ny][nx] && graph[ny][nx] == 1) {
                dq.push_back({nx, ny});
                visited[ny][nx] = true;
            }
        }
    }

    area.push_back(currentArea);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count = 0;
    vector<int> area;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 1 && !visited[i][j]) {
                bfs(graph, visited, area, j, i);
                count++;
            }
        }
    }

    cout << count << '\n';
    if (area.size() == 0) cout << 0 << '\n';
    else cout << *max_element(area.begin(), area.end()) << '\n';
}