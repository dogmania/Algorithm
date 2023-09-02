#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<char> v;
    
    for (int i = 0; i < s.length(); i++) {
        if (find(v.begin(), v.end(), s[i]) == v.end()) {
            v.push_back(s[i]);
            answer.push_back(-1);
        } else {
            for (int j = v.size() - 1; j >= 0; j--) {
                if (v[j] == s[i]) {
                    answer.push_back(v.size() - j);
                    v.push_back(s[i]);
                    break;
                }
            }
        }
    }
    
    return answer;
}