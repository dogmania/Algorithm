#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, z, m;
    int answer = 1;
    int index = 1;
    map<int, int> mp;
    cin >> n >> z >> m;

    if (m == 0) {
        cout << 1 << '\n';
        return 0;
    }

    vector<int> number(n + 1, 1);

    for (int i = 0; i < m; i++) {
        int input;
        cin >> input;
        input--;
        mp[input] = 1;
        number[input + 1] = 0;

        for (int j = 2; j <= sqrt(input); j++) {
            if (input % j == 0) {
                mp[j] = 1;
                mp[input / j] = 1;
            }
        }
    }

    while(1) {
        if (index == z) break;

        while(mp[answer] == 1) answer++;

        if (number[index] == 0) {
            answer++;
            index = 1;
            continue;
        }

        index += answer;

        if (index > n) {
            index %= n;

            if (index == 1) answer++;
        }
    }

    cout << answer << '\n';
}