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
    
    map<string, int> mp;
    int n;
    cin >> n;
    int max = 0;
    vector<string> answer;
 
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }

    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second > max) max = it->second;
    }

    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second == max) answer.push_back(it->first);
    }

    sort(answer.begin(), answer.end());

    cout << answer[0] << '\n';
}