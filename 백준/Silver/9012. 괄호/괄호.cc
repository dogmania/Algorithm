#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <sstream>
#include <stack>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    stack<char> st;
    string s;
    vector<string> answer;
    
    while (n > 0) {
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            if (st.empty()) st.push(s[i]);
            else if (st.top() == '(' && s[i] == ')') st.pop();
            else st.push(s[i]);
        }
        
        if (st.empty()) answer.push_back("YES");
        else answer.push_back("NO");
        n--;
        while (!st.empty()) st.pop();
    }
    
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }
}