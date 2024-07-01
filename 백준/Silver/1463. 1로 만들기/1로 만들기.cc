#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> dp(n + 1, INT_MAX);

    dp[1] = 0;

    for (int i = 2; i < n + 1; i++) {
        dp[i] = dp[i - 1] + 1;

        if (i % 2 == 0) dp[i] = min(dp[i / 2] + 1, dp[i]);

        if (i % 3 == 0) dp[i] = min(dp[i / 3] + 1, dp[i]);
    }

    cout << dp[n] << '\n';
}