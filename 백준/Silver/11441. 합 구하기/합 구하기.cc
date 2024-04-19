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
    
    int n, m;
    cin >> n;
    vector<int> num(n);
    vector<int> answer;
    vector<int> sum;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            sum.push_back(num[i]);
        } else {
            sum.push_back(num[i] + sum[i - 1]);
        }
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int start, end;

        cin >> start >> end;

        answer.push_back(sum[end - 1] - sum[start - 1] + num[start - 1]);
    }

    for (auto ans: answer) {
        cout << ans << '\n';
    }
}