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

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    vector<int> answer;
    int index = 0;
    
    for (int i = 1; i <= n; i++) {
        v[i - 1] = i;
    }
    
    while (!v.empty()) {
        index += k - 1;
        index %= v.size();
        answer.push_back(v[index]);
        v.erase(v.begin() + index);
    }
    
    cout << '<';
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i];
        if (i != answer.size() - 1){
            cout << ", ";
        }
    }
    cout << '>';
}