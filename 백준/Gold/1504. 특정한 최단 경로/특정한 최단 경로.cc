#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

int n, m;
int u, v;

vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int start) {
    vector<int> distance(n + 1, INF);
    priority_queue<pair<int, int>> pq;

    distance[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int currentDistance = -pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (distance[currentNode] < currentDistance) continue;

        for (int i = 0; i < graph[currentNode].size(); i++) {
            int cost = distance[currentNode] + graph[currentNode][i].second;

            if (cost < distance[graph[currentNode][i].first]) {
                distance[graph[currentNode][i].first] = cost;
                pq.push({-cost, graph[currentNode][i].first});
            }
        }
    }

    return distance;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);
    int answer1 = 0;
    int answer2 = 0;

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;

        graph[from].push_back({to, cost});
        graph[to].push_back({from, cost});
    }

     cin >> u >> v;

    vector<int> distance1 = dijkstra(graph, 1); 
    vector<int> distance2 = dijkstra(graph, u); 
    vector<int> distance3 = dijkstra(graph, v);

    answer1 = distance1[u] + distance2[v] + distance3[n]; // 1 -> u -> v -> n
    answer2 = distance1[v] + distance3[u] + distance2[n]; // 1 -> v -> u -> n

    int answer = answer1 < answer2 ? answer1 : answer2;

    if (distance1[u] >= INF || distance2[v] >= INF || distance3[n] >= INF) cout << -1 << '\n';
    else cout << answer << '\n';
}