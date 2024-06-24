#include <bits/stdc++.h>

using namespace std;

void dfs(bool visited[], vector<int> graph[], int x, vector<int>& ans_dfs) {
    visited[x] = true;
    ans_dfs.push_back(x);

    for (int i = 0; i < graph[x].size(); i++) {
        if (!visited[graph[x][i]]) dfs(visited, graph, graph[x][i], ans_dfs);
    }
}

void bfs(bool visited[], vector<int> graph[], int x, vector<int>& ans_bfs) {
    deque<int> dq;

    visited[x] = true;
    dq.push_back(x);
    ans_bfs.push_back(x);

    while(!dq.empty()) {
        int y = dq.front();
        dq.pop_front();

        for (int i = 0; i < graph[y].size(); i++) {
            if (!visited[graph[y][i]]) {
                dq.push_back(graph[y][i]);
                visited[graph[y][i]] = true;
                ans_bfs.push_back(graph[y][i]);
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, start;
    vector<int> ans_dfs;
    vector<int> ans_bfs;

    cin >> n >> m >> start;

    bool visited[n + 1];
    vector<int> graph[n + 1];

    for (int i = 0; i < m; i++) {
        int first, second;
        cin >> first >> second;

        graph[first].push_back(second);
        graph[second].push_back(first);
    }

    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    memset(visited, false, sizeof(visited));
    dfs(visited, graph, start, ans_dfs);
    memset(visited, false, sizeof(visited));
    bfs(visited, graph, start, ans_bfs);

    for (auto a: ans_dfs) {
        cout << a << ' ';
    }
    cout << '\n';

    for (auto a: ans_bfs) {
        cout << a << ' ';
    }
    cout << '\n';
}