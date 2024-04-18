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
    
    int n;
    stack<int> st;
    vector<int> answer;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int command;

        cin >> command;

        switch(command) {
            case 1: 
                int num;
                cin >> num;
                st.push(num);
                break;
            case 2:
                if (!st.empty()) {
                    answer.push_back(st.top());
                    st.pop();
                } else {
                    answer.push_back(-1);
                }
                break;
            case 3:
                answer.push_back(st.size());
                break;
            case 4:
                answer.push_back(st.empty());
                break;
            case 5:
                if (!st.empty()) {
                    answer.push_back(st.top());
                } else {
                    answer.push_back(-1);
                }
                break;
        }
    }

    for (auto ans: answer) {
        cout << ans << '\n';
    }
}