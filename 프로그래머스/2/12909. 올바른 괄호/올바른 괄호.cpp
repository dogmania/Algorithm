#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<int> st;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') st.push(s[i]);
        else {
            if (st.empty()) {
                answer = false;
                break;
            } else {
                st.pop();
            }
        }
    }
    
    if (!st.empty()) answer = false;

    return answer;
}