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
    
    int n, m;
    cin >> n >> m;
    int count = 0;
    set<string> N;
    set<string> answer;
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        N.insert(s);
    }
    
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (N.count(s) == 1) {
            answer.insert(s);
        }
    }
    
    cout << answer.size() << '\n';
    for (auto it: answer) {
        cout << it << '\n';
    }
}