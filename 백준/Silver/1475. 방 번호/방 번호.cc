#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> num(10, 0);
    string s; cin >> s;
    int len = s.length();

    for (int i = 0; i < len; i++) {
        num[s[i] - '0']++;
    }

    while(abs(num[9] - num[6]) > 1) {
        if (num[9] > num[6]) {
            num[9]--;
            num[6]++;
        } else {
            num[9]++;
            num[6]--;
        }
    }

    cout << *max_element(num.begin(), num.end()) << '\n';
}