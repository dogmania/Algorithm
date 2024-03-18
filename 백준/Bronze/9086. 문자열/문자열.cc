#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    for (auto str: s) {
        cout << str[0] << str[str.length() - 1] << '\n';
    }
}