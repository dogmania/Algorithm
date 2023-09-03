#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> v;
    
    for (auto& s: score) {
        if (v.size() < k) {
            v.push_back(s);
            sort(v.rbegin(), v.rend());
            answer.push_back(v[v.size() - 1]);
        } else if (v.size() == k && s > v[v.size() - 1]) {
            v.pop_back();
            v.push_back(s);
            sort(v.rbegin(), v.rend());
            answer.push_back(v[v.size() - 1]);
        } else answer.push_back(v[v.size() - 1]);
    }
    
    return answer;
}