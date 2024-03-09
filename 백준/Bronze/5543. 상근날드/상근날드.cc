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
    
    vector<int> v(3, 0);
    int d, e;

    cin >> v[0];
    cin >> v[1];
    cin >> v[2];

    cin >> d >> e;

    if (d > e) cout << *min_element(v.begin(), v.end()) + e - 50 << '\n';
    else cout << *min_element(v.begin(), v.end()) + d - 50 << '\n';
}