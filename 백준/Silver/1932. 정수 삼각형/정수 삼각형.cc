#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> number(n, vector<int>(n, 0));
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> number[i][j];
        }
    }

    dp[0][0] = number[0][0];

    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + number[i][0];
        dp[i][i] = dp[i - 1][i - 1] + number[i][i];

        for (int j = 1; j < i; j++) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + number[i][j];
        }
    }

    cout << *max_element(dp[n - 1].begin(), dp[n - 1].end()) << '\n';
}