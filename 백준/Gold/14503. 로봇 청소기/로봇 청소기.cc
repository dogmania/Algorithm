#include <bits/stdc++.h>

using namespace std;

int n, m;
int x, y, d;

int bfs(vector<vector<int>>& graph) {
    deque<tuple<int, int, int>> dq;
    int count = 0;
    bool isEmpty = true;

    // 방향 북, 동, 남, 서
    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};

    dq.push_back({x, y, d});

    while(!dq.empty()) {
        tuple<int, int, int> currentNode = dq.front();
        dq.pop_front();

        int currentX = get<0>(currentNode);
        int currentY = get<1>(currentNode);
        int currentDirection = get<2>(currentNode);
        bool cleaned = false;

        if (graph[currentY][currentX] == 0) {
            graph[currentY][currentX] = 2;
            count++;
        }

        for (int i = 0; i < 4; i++) {
            currentDirection = (currentDirection + 3) % 4;

            int nx = currentX + dx[currentDirection];
            int ny = currentY + dy[currentDirection];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && graph[ny][nx] == 0) {
                dq.push_back({nx, ny, currentDirection});
                cleaned = true;
                break;
            }
        }

        if (!cleaned) {
            int backDirection = (currentDirection + 2) % 4;
            int backX = currentX + dx[backDirection];
            int backY = currentY + dy[backDirection];

            if (backX >= 0 && backX < m && backY >= 0 && backY < n && graph[backY][backX] != 1) {
                dq.push_back({backX, backY, currentDirection});
            } else {
                return count;
            }
        }
    }

    return count;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    cin >> y >> x >> d;

    vector<vector<int>> graph(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    int answer = bfs(graph);
    cout << answer << '\n';
}