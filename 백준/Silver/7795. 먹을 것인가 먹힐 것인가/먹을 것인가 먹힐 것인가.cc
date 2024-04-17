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
    
    int t;
    cin >> t;
    vector<int> answer;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        int count = 0;

        vector<int> a(n, 0);
        vector<int> b(m, 0);

        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }

        for (int j = 0; j < m; j++) {
            cin >> b[j];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (a[j] <= b[k]) break;
                else count++;
            }
        }

        answer.push_back(count);
    }

    for (auto ans: answer) {
        cout << ans << '\n';
    }
}