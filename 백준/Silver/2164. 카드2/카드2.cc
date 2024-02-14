#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <sstream>
#include <stack>
#include <queue>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    queue<int> q;
    int num;
    
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    
    while(q.size() != 1) {
        q.pop();
        num = q.front();
        q.pop();
        q.push(num);
    }
    
    cout << q.front();
}