#include <bits/stdc++.h>

using namespace std;

string solution(string s) {    
    int count = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            count = 0;
            continue;
        }
        
        if (count % 2 == 0) {
            if (s[i] >= 97 && s[i] <= 122) {
                s[i] -= 32;
            }
        } else {
            if (s[i] >= 65 && s[i] <= 90) {
                s[i] += 32;
            }
        }
        
        count++;
    }
    
    return s;
}