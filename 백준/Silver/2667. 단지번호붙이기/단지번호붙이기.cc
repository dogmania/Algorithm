#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<bool>>& visited, vector<vector<int>>& graph, int y, int x, int& count, int n) {
    visited[y][x] = true;

    int dy[] = {-1, 1, 0, 0};
    int dx[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[ny][nx] && graph[ny][nx] == 1) {
            count++;
            dfs(visited, graph, ny, nx, count, n);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int> (n, 0));
    vector<vector<bool>> visited(n, vector<bool> (n, false));
    vector<int> answer;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < n; j++) {
            graph[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1 && !visited[i][j]) {
                int count = 1;
                dfs(visited, graph, i, j, count, n);
                answer.push_back(count);
            }
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << '\n';

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << '\n';
    }
}