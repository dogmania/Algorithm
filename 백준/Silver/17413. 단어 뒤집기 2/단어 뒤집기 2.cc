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
    
    string s;
    stack<char> st;
    int index = 0;
    getline(cin, s);

    for (int i = 0; i < s.length(); i++) {
        if(s[i] == '<') {
            st.push(s[i]);
            if (i != 0) {
                reverse(s.begin() + index, s.begin() + i);
            }
            continue;
        } else if(s[i] == '>') {
            st.pop();
            index = i + 1;
            continue;
        } else if(s[i] == ' ') {
            if (index == i) index++;
            else if (index < i && st.empty()) {
                reverse(s.begin() + index, s.begin() + i);
                index = i + 1;
            }
        }

        if (i == s.length() - 1 && index < s.length()) {
            reverse(s.begin() + index, s.end());
        }
    }

    cout << s << '\n';
}