#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph(501, vector<int>(501, 0));
vector<vector<bool>> visited(501, vector<bool>(501, false));

int answer = 1e9;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void setDangerousArea(int x1, int y1, int x2, int y2) {
    int minX = min(x1, x2);
    int maxX = max(x1, x2);
    int minY = min(y1, y2);
    int maxY = max(y1, y2);

    for (int i = minY; i <= maxY; i++) {
        for (int j = minX; j <= maxX; j++) {
            if (graph[i][j] != 2) graph[i][j] = 1;
        }
    }
}

void setDeathArea(int x1, int y1, int x2, int y2) {
    int minX = min(x1, x2);
    int maxX = max(x1, x2);
    int minY = min(y1, y2);
    int maxY = max(y1, y2);

    for (int i = minY; i <= maxY; i++) {
        for (int j = minX; j <= maxX; j++) {
            graph[i][j] = 2;
        }
    }
}

void bfs() {
    deque<tuple<int, int, int>> dq;
    visited[0][0] = true;
    dq.push_back({0, 0, 0});

    while(!dq.empty()) {
        auto [x, y, cost] = dq.front();
        dq.pop_front();

        if (x == 500 && y == 500) {
            answer = min(answer, cost);
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx <= 500 && ny >= 0 && ny <= 500 && !visited[ny][nx] && graph[ny][nx] != 2) {
                visited[ny][nx] = true;

                if (graph[ny][nx] == 1) {
                    dq.push_back({nx, ny, cost + graph[ny][nx]});
                } else {
                    dq.push_front({nx, ny, cost});
                }
            }
        }
    }

    if (!visited[500][500]) answer = -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        setDangerousArea(x1, y1, x2, y2);
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        setDeathArea(x1, y1, x2, y2);
    }

    if (graph[500][500] == 2) {
        cout << -1 << '\n';
    } else {
        bfs();
        cout << answer << '\n';
    }
}