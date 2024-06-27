#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<bool>> visited, vector<vector<int>> graph, tuple<int, int> end, tuple<int, int, int> start) {
    deque<tuple<int, int, int>> dq;
    int end_x = get<1>(end);
    int end_y = get<0>(end);

    visited[0][0] = true;
    dq.push_back(start);

    while(!dq.empty()) {
        tuple<int, int, int> y = dq.front();
        int current_x = get<1>(y);
        int current_y = get<0>(y);
        int count = get<2>(y);

        if (current_x == end_x && current_y == end_y) {
            cout << count << '\n';
            return;
        }

        dq.pop_front();

        if (current_x + 1 <= end_x && graph[current_y][current_x + 1] == 1 && !visited[current_y][current_x + 1]) {
            dq.push_back({current_y, current_x + 1, count + 1});
            visited[current_y][current_x + 1] = true;
        }
        if (current_y + 1 <= end_y && graph[current_y + 1][current_x] == 1 && !visited[current_y + 1][current_x]) {
            dq.push_back({current_y + 1, current_x, count + 1});
            visited[current_y + 1][current_x] = true;
        }
        if (current_x - 1 >= 0 && graph[current_y][current_x - 1] == 1 && !visited[current_y][current_x - 1]) {
            dq.push_back({current_y, current_x - 1, count + 1});
            visited[current_y][current_x - 1] = true;
        }
        if (current_y - 1 >= 0 && graph[current_y - 1][current_x] == 1 && !visited[current_y - 1][current_x]) {
            dq.push_back({current_y - 1, current_x, count + 1});
            visited[current_y - 1][current_x] = true;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, count = 1;
    cin >> n >> m;
    tuple<int, int> end = make_tuple(n - 1,  m - 1);
    tuple<int, int, int> start = make_tuple(0, 0, count);

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> graph(n, vector<int> (m, 0));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            graph[i][j] = s[j] - '0';
        }
    }

    bfs(visited, graph, end, start);
}