#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

int n, m;
int start, destination;

void dijkstra(vector<vector<pair<int, int>>>& graph, vector<int>& distance) {
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
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> distance(n + 1, INF);

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;

        graph[from].push_back({to, cost});
    }

    cin >> start >> destination;

    dijkstra(graph, distance);

    cout << distance[destination] << '\n';
}