#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, num;
    cin >> n;
    int N[n];
    
    for (int k = 0; k < n; k++) {
        cin >> N[k];
    }
    
    cin >> m;
    
    sort(N, N + n);
    
    for (int i = 0; i < m; i++) {
        cin >> num;
        cout << binary_search(N, N + n, num) << '\n';
    }
}