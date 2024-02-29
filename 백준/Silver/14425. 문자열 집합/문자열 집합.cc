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

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    map<string, int> mp;
    int answer = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        mp[s] = 0;
    }

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;

        if (mp.find(s) != mp.end()) {
            answer++;
        }
    }

    cout << answer << '\n';
}