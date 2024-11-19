#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int index = 0;
    cin >> n;
    vector<int> num(n, 0);
    map<int, int> mp;
    set<int> s;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
        s.insert(num[i]);
    }

    for (auto &component: s) {
        mp[component] = index;
        index++;
    }

    for (int i = 0; i < n; i++) {
        cout << mp[num[i]] << ' ';
    }

    cout << '\n';
}