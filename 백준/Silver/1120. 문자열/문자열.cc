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
    
    string a, b;
    cin >> a >> b;
    int l = a.length();
    int answer = l;

    for (int i = 0; i <= (b.length() - a.length()); i++) {
        string sub_b = b.substr(i, l);
        int ans = 0;

        for (int j = 0; j < l; j++) {
            if (a[j] != sub_b[j]) ans++;
        }

        if (ans < answer) answer = ans;
    }

    cout << answer << '\n';
}