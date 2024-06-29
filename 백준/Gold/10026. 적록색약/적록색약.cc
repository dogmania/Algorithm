#include <bits/stdc++.h>

const int R = 1;
const int G = 2;
const int B = 3;

using namespace std;

void bfs(vector<vector<char>> graph, vector<vector<bool>>& visited, int y, int x, int n) {
    deque<tuple<int, int>> dq;

    dq.push_back({x, y});
    visited[y][x] = true;

    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    while(!dq.empty()) {
        tuple<int, int> current_value = dq.front();
        dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int current_x = get<0>(current_value);
            int current_y = get<1>(current_value);
            int nx = current_x + dx[i];
            int ny = current_y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (graph[current_y][current_x] == graph[ny][nx] && !visited[ny][nx]) {
                    dq.push_back({nx, ny});
                    visited[ny][nx] = true;
                }
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, count = 0;
    cin >> n;
    vector<int> answer;
    vector<vector<char>> abnormal_graph(n, vector<char>(n));
    vector<vector<char>> normal_graph(n, vector<char>(n));
    vector<vector<bool>> abnormal_visited(n, vector<bool>(n, false));
    vector<vector<bool>> normal_visited(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < n; j++) {
            if (s[j] == 'R') {
                abnormal_graph[i][j] = R;
                normal_graph[i][j] = R;
            }
            else if (s[j] == 'G') {
                abnormal_graph[i][j] = R;
                normal_graph[i][j] = G;
            }
            else if (s[j] == 'B') {
                abnormal_graph[i][j] = B;
                normal_graph[i][j] = B;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!normal_visited[i][j]) {
                bfs(normal_graph, normal_visited, i, j, n);
                count++;
            }
        }
    }

    answer.push_back(count);
    count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!abnormal_visited[i][j]) {
                bfs(abnormal_graph, abnormal_visited, i, j, n);
                count++;
            }
        }
    }

    answer.push_back(count);

    cout << answer[0] << ' ' << answer[1] << '\n';
}