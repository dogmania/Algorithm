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
    
    int m, n;
    cin >> m >> n;
    vector<int> v = {2, 3, 5, 7};
    bool p = true;

    for (int i = 11; i <= n; i++) {
        p = true;
        if (i <= 10) continue;
        if (i % 10 == 1 || i % 10 == 3 || i % 10 == 7 || i % 10 == 9) {
            for (int j = 0; j < v.size(); j++) {
                if (i % v[j] == 0) {
                    p = false;
                    break;
                }
                if (v[j] >= sqrt(i)) break;
            }
            if (p) {
                v.push_back(i);
            }
        }
    }

    for (int i = 0; i < v.size(); i++) {
        if (v[i] >= m && v[i] <= n) cout << v[i] << '\n';
    }
}