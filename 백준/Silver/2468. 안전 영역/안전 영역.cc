#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void bfs(vector<vector<int>>& graph, vector<vector<bool>>& visited, int n, int boundary, int y, int x) {
    deque<tuple<int, int>> dq;

    visited[y][x] = true;
    dq.push_back({x, y});

    while(!dq.empty()) {
        tuple<int, int> currentNode = dq.front();
        dq.pop_front();
        int currentX = get<0>(currentNode);
        int currentY = get<1>(currentNode);

        for (int i = 0; i < 4; i++) {
            int nx = currentX + dx[i];
            int ny = currentY + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[ny][nx] && graph[ny][nx] > boundary) {
                dq.push_back({nx, ny});
                visited[ny][nx] = true;
            }
        }
    }
}  

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));
    vector<int> answer;
    set<int> st;

    st.insert(0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            st.insert(graph[i][j]);
        }
    }

    for (auto s: st) {
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] > s && !visited[i][j]) {
                    bfs(graph, visited, n, s, i, j);
                    count++;
                }
            }
        }

        answer.push_back(count);
    }

    if (answer.size() == 0) cout << 0 << '\n';
    else cout << *max_element(answer.begin(), answer.end()) << '\n';
}