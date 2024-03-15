#include <bits/stdc++.h>

using namespace std;

int main() {
    string num;
    
    cin >> num;
    
    sort(num.rbegin(), num.rend());
    
    cout << num << '\n';
}