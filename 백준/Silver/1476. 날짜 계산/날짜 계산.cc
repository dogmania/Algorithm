#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int e, s, m;
    int answer = 1;
    cin >> e >> s >> m;

    while(1) {
        if ((answer - e) % 15 == 0 && (answer - s) % 28 == 0 && (answer - m) % 19 == 0) {
            cout << answer << '\n';
            break;
        }
        answer++;
    }
}