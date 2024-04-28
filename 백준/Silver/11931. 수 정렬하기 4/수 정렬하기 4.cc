#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> num(n, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    
    sort(num.rbegin(), num.rend());
    
    for (auto ans: num) {
        cout << ans << '\n';
    }
}