#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; cin >> n;
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        mp[num] = 1;
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;

        if (mp[num] == 1) cout << 1 << ' ';
        else cout << 0 << ' ';
    }

    cout << '\n';
}