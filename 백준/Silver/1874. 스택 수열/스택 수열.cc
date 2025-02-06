#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int currentNum = 1;
    vector<char> answer;
    cin >> n;
    deque<int> num;
    stack<int> st;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        num.push_back(input);
    }

    while (!num.empty()) {
        if (num.front() == currentNum) {
            num.pop_front();
            currentNum++;
            answer.push_back('+');
            answer.push_back('-');
        } else if (num.front() > currentNum) {
            while (currentNum < num.front()) {
                st.push(currentNum);
                answer.push_back('+');
                currentNum++;
            }
        } else {
            if (st.top() != num.front()) {
                cout << "NO" << '\n';
                return 0;
            } else {
                st.pop();
                num.pop_front();
                answer.push_back('-');
            }
        }
    }

    for (auto ans: answer) {
        cout << ans << '\n';
    }
}