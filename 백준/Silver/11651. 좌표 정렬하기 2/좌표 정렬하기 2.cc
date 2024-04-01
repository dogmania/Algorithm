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

bool cmp(vector<int> v1, vector<int> v2) {
    if (v1[1] == v2[1]) {
        return v1[0] <= v2[0];
    } else {
        return v1[1] <= v2[1];
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<vector<int>> num;

    for (int i = 0; i < n; i++) {
        vector<int> v;
        int x, y;

        cin >> x >> y;
        v.push_back(x);
        v.push_back(y);

        num.push_back(v);
    }

    sort(num.begin(), num.end(), cmp);

    for (auto v: num) {
        cout << v[0] << ' ' << v[1] << '\n';
    }
}