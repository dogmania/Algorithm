#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <sstream>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <iterator>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    map<string, string> mp;

    for (int i = 0;i < n; i++) {
        string site;
        string password;

        cin >> site >> password;

        mp[site] = password;
    }

    for (int i = 0; i < m; i++) {
        string site;
        
        cin >> site;

        cout << mp[site] << '\n';
    }
}