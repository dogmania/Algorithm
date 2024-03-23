#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> num(3, 0);
    
    cin >> num[0] >> num[1] >> num[2];
    
    sort(num.begin(), num.end());
    
    cout << num[0] << ' ' << num[1] << ' ' << num[2] << '\n';
}