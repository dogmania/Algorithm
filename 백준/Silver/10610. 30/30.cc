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
    
    string num;
    cin >> num;
    int sum = 0;
    bool p = false;

    for (int i = 0; i < num.length(); i++) {
        sum += (num[i] - '0') % 3;
        if (num[i] == '0') p = true;
    }

    if (sum % 3 != 0 || !p) cout << -1 << '\n';
    else {
        sort(num.rbegin(), num.rend());
        cout << num << '\n';
    }
}