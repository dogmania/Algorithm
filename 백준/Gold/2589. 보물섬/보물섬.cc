#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int x;
    int y;
    int distance;

    Node (int x, int y, int distance) {
        this->x = x;
        this->y = y;
        this->distance = distance;
    }
};

int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(vector<string> &graph, Node start) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> d(n, vector<int>(m, 0));
    deque<Node> dq;
    int maxDistance = 0;

    dq.push_back(start);
    visited[start.y][start.x] = true;

    while(!dq.empty()) {
        auto [x, y, distance] = dq.front();
        dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[ny][nx] && graph[ny][nx] == 'L') {
                visited[ny][nx] = true;
                dq.push_back(Node(nx, ny, distance + 1));
                d[ny][nx] = distance + 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            maxDistance = max(maxDistance, d[i][j]);
        }
    }

    return maxDistance;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    vector<string> graph;
    int answer = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        graph.push_back(s);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 'L') {
                int result = bfs(graph, Node(j, i, 0));
                answer = max(answer, result);
            }
        }
    }

    cout << answer << '\n';
}