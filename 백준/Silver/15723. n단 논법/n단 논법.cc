#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    map<char, char> mp;
    vector<char> answer;
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s1, s2, s3;

        cin >> s1 >> s2 >> s3;

        mp[s1[0]] = s3[0];
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        string s1, s2, s3;

        cin >> s1 >> s2 >> s3;

        char key = s1[0];
        char target = s3[0];

        while(1) {
            if (mp[key] == target) {
                answer.push_back('T');
                break;
            }

            key = mp[key];

            if (mp.find(key) == mp.end()) {
                answer.push_back('F');
                break;
            }
        }
    }

    for (auto ans: answer) {
        cout << ans << '\n';
    }
}