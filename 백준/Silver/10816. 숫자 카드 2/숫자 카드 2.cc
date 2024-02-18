#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <sstream>
#include <stack>
#include <queue>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    int temp;
    map<int, int> mp;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> temp;
        mp[temp]++;
    }
    
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        cout << mp[temp] << ' ';
    }
}