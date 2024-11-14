#include <bits/stdc++.h>

using namespace std;

int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs(vector<vector<int>> graph, vector<vector<bool>> visited, deque<pair<int, int>> walls) {
    for (auto wall : walls) {
        graph[wall.second][wall.first] = 1;
    }

    int count = 0;
    deque<pair<int, int>> dq;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 2) {
                dq.push_back({j, i});
                visited[i][j] = true;
            }
        }
    }

    while(!dq.empty()) {
        pair<int, int> currentNode = dq.front();
        dq.pop_front();
        int currentX = currentNode.first;
        int currentY = currentNode.second;

        for (int i = 0; i < 4; i++) {
            int nx = currentX + dx[i];
            int ny = currentY + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[ny][nx] && graph[ny][nx] == 0) {
                graph[ny][nx] = 2;
                dq.push_back({nx, ny});
                visited[ny][nx] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 0) count++;
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int answer = 0;
    vector<vector<int>> graph(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<pair<int, int>> safeArea;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0) safeArea.push_back({j, i});
        }
    }

    int safeAreaCount = safeArea.size();
    for (int i = 0; i < safeAreaCount; i++) {
        for (int j = i + 1; j < safeAreaCount; j++) {
            for (int k = j + 1; k < safeAreaCount; k++) {
                deque<pair<int, int>> dq = { safeArea[i], safeArea[j], safeArea[k] };

                int ans = bfs(graph, visited, dq);
                if (ans > answer) answer = ans;
            }
        }
    }

    cout << answer << '\n';
}