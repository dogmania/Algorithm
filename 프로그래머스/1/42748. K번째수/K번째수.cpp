#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> v;
    
    for (auto& c: commands) {
        for (int i = c[0] - 1; i < c[1]; i++) {
            v.push_back(array[i]);
        }
        sort(v.begin(), v.end());
        answer.push_back(v[c[2] - 1]);
        v.clear();
    }
    
    return answer;
}