#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector<int> num(n, 0);
    vector<int> dp(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    if (n == 1) {
        cout << num[0] << '\n';
        return 0;
    }

    dp[0] = num[0];
    dp[1] = num[0] + num[1];
    if (n > 2) {
        dp[2] = max(num[2] + num[1], num[2] + num[0]);
        dp[2] = max(dp[2], dp[1]);
    }

    for (int i = 3; i < n; i++) {
        dp[i] = max(num[i] + num[i - 1] + dp[i - 3], num[i] + dp[i - 2]);
        dp[i] = max(dp[i], dp[i - 1]);
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';
}