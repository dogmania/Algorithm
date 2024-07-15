#include <bits/stdc++.h>

using namespace std;

int n, k;

int bfs(vector<bool>& visited) {
    deque<tuple<int, int>> dq;

    dq.push_back({n, 0});
    visited[n] = true;

    while(!dq.empty()) {
        tuple<int, int> currentNode = dq.front();
        dq.pop_front();

        int currentX = get<0>(currentNode);
        int currentTime = get<1>(currentNode);

        if (currentX == k) return currentTime;

        if (currentX * 2 < 100001 && !visited[currentX * 2]) {
            dq.push_back({currentX * 2, currentTime});
            visited[currentX * 2] = true;
        }

        if (currentX - 1 >= 0 && currentX - 1 < 100001 && !visited[currentX - 1]) {
            dq.push_back({currentX - 1, currentTime + 1});
            visited[currentX - 1] = true;
        }

        if (currentX + 1 < 100001 && !visited[currentX + 1]) {
            dq.push_back({currentX + 1, currentTime + 1});
            visited[currentX + 1] = true;
        }
    }

    return -1;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> n >> k;
    vector<bool> visited(100001, false);

    cout << bfs(visited) << '\n';
}