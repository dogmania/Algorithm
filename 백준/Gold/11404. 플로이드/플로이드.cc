#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

int n, m;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (i == j) graph[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        if (cost < graph[from][to]) graph[from][to] = cost;
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            for (int k = 1; k < n + 1; k++) {
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
            }
        }
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (graph[i][j] == INF) cout << 0 << ' ';
            else cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
}