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
    cin >> n >> m;

    vector<int> A(n, 0);
    vector<int> B(m, 0);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    A.insert(A.end(), B.begin(), B.end());
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());

    int count = n + m - A.size();

    cout << A.size() - count << '\n';
}