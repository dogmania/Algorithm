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
    
    int n;
    cin >> n;
    vector<int> v1(n);
    vector<int> v2(n);
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> v2[i];
    }
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    for (int i = 0; i < n; i++) {
        answer += v1[i] * v2[n - i - 1];
    }
    
    cout << answer << '\n';
}