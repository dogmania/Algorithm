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

bool cmp(vector<int> num1, vector<int> num2) {
    if (num1[0] == num2[0]) {
        return num1[1] <= num2[1];
    } else {
        return num1[0] <= num2[0];
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;

    cin >> n;

    vector<vector<int>> v(n, vector<int>(2, 0));

    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << v[i][0] << ' ' << v[i][1] << '\n';
    }
}