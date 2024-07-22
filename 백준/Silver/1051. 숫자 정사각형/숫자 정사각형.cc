#include <bits/stdc++.h>

using namespace std;

int n , m; 

int calArea(int x, int y, vector<vector<int>>& arr) {
    int i = 1;
    int nextX = x + i;
    int nextY = y + i;
    int answer = 1;

    while (nextX < m && nextY < n) {
        if (arr[y][x] == arr[nextY][x] && arr[y][x] == arr[y][nextX] && arr[y][x] == arr[nextY][nextX]) {
            answer = (i + 1) * (i + 1);
        }

        i++;
        nextX = x + i;
        nextY = y + i;
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    int answer = 1;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int ans = calArea(j, i, arr);

            if (ans > answer) answer = ans;
        }
    }

    cout << answer << '\n';
}