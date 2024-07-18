#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

int v, e, start;

void dijkstra(vector<vector<pair<int, int>>>& graph, vector<int>& d) {
    priority_queue<pair<int, int>> pq;

    d[start] = 0;
    pq.push({0, start});    //거리, 노드

    while(!pq.empty()) {
        int distance = -pq.top().first; //현재까지 거리
        int currentNode = pq.top().second; //현재 노드
        pq.pop();

        if (d[currentNode] < distance) continue;

        for (int i = 0; i < graph[currentNode].size(); i++) {
            int cost = d[currentNode] + graph[currentNode][i].second;

            if (cost < d[graph[currentNode][i].first]) {
                d[graph[currentNode][i].first] = cost;
                pq.push({-cost, graph[currentNode][i].first});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v >> e;
    cin >> start;

    vector<vector<pair<int, int>>> graph(v + 1);
    vector<int> d(v + 1, INF);

    for (int i = 0; i < e; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;

        graph[from].push_back({to, cost});
    }

    dijkstra(graph, d);

    for (int i = 1; i < v + 1; i++) {
        if (d[i] == INF) cout << "INF" << '\n';
        else cout << d[i] << '\n';
    }
}