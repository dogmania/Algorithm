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
    
    string s;
    vector<int> v(26,0);
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 97) {
            v[(s[i] - 32) % 65]++;
        } else {
            v[s[i] % 65]++;
        }
    }

    int max = *max_element(v.begin(), v.end());
    int max_index = max_element(v.begin(), v.end()) - v.begin();
    char c = max_index + 'A';

    if (count(v.begin(), v.end(), max) != 1) cout << '?' << '\n';
    else cout << c << '\n';
}