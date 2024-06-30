#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>>& graph, vector<vector<bool>>& visited, deque<tuple<int, int>>& dq, int x, int y, int& count) {
    deque<tuple<int, int>> new_dq;

    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    while(!dq.empty()) {
        tuple<int, int> current_node = dq.front();
        dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int nx = get<0>(current_node) + dx[i];
            int ny = get<1>(current_node) + dy[i];

            if (nx >= 0 && nx < x && ny >= 0 && ny < y && !visited[ny][nx] && graph[ny][nx] == 0) {
                new_dq.push_back({nx, ny});
                graph[ny][nx] = 1;
                visited[ny][nx] = true;
                count++;
            }
        }
    }

    dq = new_dq;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int m, n;   //m이 가로, n이 세로
    int current_count = 0;
    int last_count = 0;
    int answer = 0;
    cin >> m >> n;
    vector<vector<int>> graph(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    deque<tuple<int, int>> dq;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 1) {
                dq.push_back({j, i});   // x,y 순으로 deque에 삽입
                visited[i][j] = true;
                current_count++;
            } 
        }
    }

    while(1) {
        if (current_count == last_count) break;
        last_count = current_count;

        bfs(graph, visited, dq, m, n, current_count);

        if (current_count != last_count) answer++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 0) {
                answer = -1;
                break;
            }
        }
    }

    cout << answer << '\n';
}