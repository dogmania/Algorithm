#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <sstream>
#include <stack>
#include <queue>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    string s, s1;
    queue<int> q;
    vector<int> answer;
    
    for (int i = 0; i <= n; i++) {
        getline(cin, s);
        
        if (s.length() >= 6) {
            stringstream ss(s);
            while (ss >> s1) {
                if (s1 == "push") {
                    continue;
                } else {
                    q.push(stoi(s1));
                }
            }
        } else if (s == "front") {
            if (q.empty()) {
                answer.push_back(-1);
            } else {
                answer.push_back(q.front());
            }
        } else if (s == "back") {
            if (q.empty()) {
                answer.push_back(-1);
            } else {
                answer.push_back(q.back());
            }
        } else if (s == "pop") {
            if (q.empty()) {
                answer.push_back(-1);
            } else {
                answer.push_back(q.front());
                q.pop();
            }
        } else if (s == "size") {
            answer.push_back(q.size());
        } else if (s == "empty") {
            answer.push_back(q.empty());
        }
    }
    
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << '\n';
    }
}