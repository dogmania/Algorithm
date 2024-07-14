#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCase;
    cin >> testCase;

    for (int t = 0; t < testCase; t++) {
        int n;
        cin >> n;
        vector<vector<int>> sticker(2, vector<int>(n, 0));
        vector<vector<int>> dp(2, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            cin >> sticker[0][i];
        }

        for (int i = 0; i < n; i++) {
            cin >> sticker[1][i];
        }

        dp[0][0] = sticker[0][0];
        dp[1][0] = sticker[1][0];

        if (n == 1) {
            cout << max(dp[0][0], dp[1][0]) << '\n';
        } else {
            dp[0][1] = sticker[0][1] + sticker[1][0];
            dp[1][1] = sticker[1][1] + sticker[0][0];

            for (int i = 2; i < n; i++) {
                dp[0][i] = sticker[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
                dp[1][i] = sticker[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
            }

            cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
        }
    }
}