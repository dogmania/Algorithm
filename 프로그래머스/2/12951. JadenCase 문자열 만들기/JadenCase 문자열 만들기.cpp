#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    bool first = true;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            first = true;
            continue;
        }
        
        if (first) {
            if (s[i] >= 97 && s[i] <= 122) {
                s[i] -= 32;
            }
        } else {
            if (s[i] >= 65 && s[i] <= 90) {
                s[i] += 32;
            }
        }
        
        first  = false;
    }
    
    return s;
}