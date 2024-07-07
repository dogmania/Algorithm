#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(3, 0));
    vector<vector<int>> dp(n, vector<int>(3, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> cost[i][j];
        }
    }

    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            switch(j) {
                case 0:
                    dp[i][j] = cost[i][j] + min(dp[i - 1][1], dp[i - 1][2]);
                    break;
                case 1:
                    dp[i][j] = cost[i][j] + min(dp[i - 1][0], dp[i - 1][2]);
                    break;
                case 2:
                    dp[i][j] = cost[i][j] + min(dp[i - 1][0], dp[i - 1][1]);
                    break;
            }
        }
    }

    cout << *min_element(dp[n - 1].begin(), dp[n - 1].end()) << '\n';
}