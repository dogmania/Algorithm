#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, boom;
    cin >> s >> boom;
    string prevStr;
    int boomLen = boom.length();
    string answer;

    for(char c: s) {
        answer.push_back(c);

        if (answer.length() >= boomLen && answer.substr(answer.length() - boomLen, boomLen) == boom) {
            answer.erase(answer.size() - boomLen, boomLen);
        }
    }

    if (answer.empty()) cout << "FRULA" << '\n';
    else cout << answer << '\n';
}