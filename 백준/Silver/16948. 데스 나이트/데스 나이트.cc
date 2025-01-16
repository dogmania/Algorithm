#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int r1, c1, r2, c2;

    cin >> n >> r1 >> c1 >> r2 >> c2;;

    int answer = 1e9;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    deque<tuple<int, int, int>> dq;
    int dx[] = {-2, -2, 0, 0, 2, 2};
    int dy[] = {-1, 1, -2, 2, -1, 1};

    

    dq.push_back({r1, c1, 0});
    visited[c1][r1] = true;

    while (!dq.empty()) {
        auto [x, y, count] = dq.front();
        dq.pop_front();

        if (x == r2 && y == c2) {
            answer = min(answer, count);
        }

        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[ny][nx]) {
                visited[ny][nx] = true;

                dq.push_back({nx, ny, count + 1});
            }
        }
    }

    if (answer == 1e9) answer = -1;

    cout << answer << '\n';
}