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

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    stack<char> st;
    vector<string> answer;
    
    while(1) {
        getline(cin, s);
        
        if (s == ".") break;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push('(');
            } else if (s[i] == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                    continue;
                } else {
                    st.push(')');
                    break;
                }
            } else if (s[i] == '[') {
                st.push('[');
            } else if (s[i] == ']') {
                if (!st.empty() && st.top() == '[') {
                    st.pop();
                    continue;
                } else {
                    st.push(']');
                    break;
                }
            }
        }
        
        if (st.empty()) {
            answer.push_back("yes");
        } else {
            answer.push_back("no");
        }
        
        while(!st.empty()) st.pop();
    }
    
    for (auto ans: answer) {
        cout << ans << '\n';
    }
}