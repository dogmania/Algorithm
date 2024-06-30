#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};

void bfs(vector<vector<int>> graph, vector<vector<bool>>& visited, tuple<int, int> start, int x, int y) {
    deque<tuple<int, int>> dq;

    dq.push_back(start);

    while(!dq.empty()) {
        tuple<int, int> current_node = dq.front();
        dq.pop_front();

        for (int i = 0; i < 8; i++) {
            int nx = get<0>(current_node) + dx[i];
            int ny = get<1>(current_node) + dy[i];

            if (nx >= 0 && nx < x && ny >= 0 && ny < y && !visited[ny][nx] && graph[ny][nx] == 1) {
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
    
    int w, h;
    vector<int> answer;

    cin >> w >> h;

    while(w != 0 && h != 0) {
        vector<vector<int>> graph(h, vector<int>(w, 0));
        vector<vector<bool>> visited(h, vector<bool>(w, 0));
        int count = 0;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> graph[i][j];
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (graph[i][j] == 1 && !visited[i][j]) {
                    visited[i][j] = true;
                    bfs(graph, visited, {j, i}, w, h);
                    count++;
                } 
            }
        }

        answer.push_back(count);

        cin >> w >> h;
    }

    for (auto ans: answer) {
        cout << ans << '\n';
    }
}