#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int answer = 0;
    vector<int> cost(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    sort(cost.rbegin(), cost.rend());

    for (int i = 0; i < n; i++) {
        if (i % 3 != 2) {
            answer += cost[i];
        }
    }

    cout << answer << '\n';
}