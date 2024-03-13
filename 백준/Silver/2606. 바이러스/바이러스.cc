#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <sstream>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <iterator>

using namespace std;

void bfs(vector<vector<int>> graph, bool visited[], int start) {
    deque<int> dq;

    dq.push_back(start);
    visited[start] = true;

    while (!dq.empty()) {
        int num = dq.front();
        dq.pop_front();

        for (int i = 0; i < graph[num].size(); i++) {
            if (!visited[graph[num][i]]) {
                dq.push_back(graph[num][i]);
                visited[graph[num][i]] = true;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    int count;
    int answer = 0;
    cin >> n;
    cin >> count;

    vector<vector<int>> v(n + 1, vector<int>(0));
    bool visited[n + 1];
    
    for (int i = 0; i < sizeof(visited); i++) {
        visited[i] = false;
    }

    for (int i = 0; i < count; i++) {
        int m, num;
        cin >> m;
        cin >> num;
        v[m].push_back(num);
        v[num].push_back(m);
    }

    bfs(v, visited, 1);

    for (int i = 2; i < sizeof(visited); i++) {
        if (visited[i]) answer++;
    }

    cout << answer << '\n';
}