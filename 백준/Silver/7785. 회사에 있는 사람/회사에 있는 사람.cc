#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<string, int> mp;
    int n; cin >> n;
    vector<string> answer;

    for (int i = 0; i < n; i++) {
        string name, command;
        cin >> name >> command;

        if (command == "enter") mp[name] = 1;
        else if (command == "leave") {
            if (mp[name] == 1) {
                mp[name] = 0;
            }
        }
    }

    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second == 1) answer.push_back(it->first);
    }

    sort(answer.rbegin(), answer.rend());

    for (auto ans: answer) {
        cout << ans << '\n';
    }
}