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
    string s, s1;
    stack<int> st;
    cin.ignore();
    string num;
    vector<int> answer;
    
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        
        if (s.length() > 5) {
            stringstream ss(s);
            ss >> s1 >> num;
            st.push(stoi(num));
        } else if (s.length() == 5) {
            answer.push_back(st.empty());
        } else if (s.length() == 4) {
            answer.push_back(st.size());
        } else if (s.length() == 3) {
            switch(s[0]) {
                case 'p':
                    if (st.empty()) answer.push_back(-1);
                    else {
                        answer.push_back(st.top());
                        st.pop();
                    }
                    break;
                case 't':
                    if (st.empty()) answer.push_back(-1);
                    else {
                        answer.push_back(st.top());
                    }
                    break;
            }
        }
    }
    
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }
}