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

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    string s;
    deque<int> dq;
    vector<int> answer;
    
    cin.ignore();
    
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        
        if (s.length() >= 11) {
            stringstream ss(s);
            string s1, s2;
            
            ss >> s1 >> s2;
            
            if (s1 == "push_back") {
                dq.push_back(stoi(s2));
            } else if (s1 == "push_front") {
                dq.push_front(stoi(s2));
            }
            
        } else {
            if (s == "pop_front") {
                if (dq.empty()) {
                    answer.push_back(-1);
                } else {
                    int num = dq.front();
                    answer.push_back(num);
                    dq.pop_front();
                }
            } else if (s == "pop_back") {
                if (dq.empty()) {
                    answer.push_back(-1);
                } else {
                    int num = dq.back();
                    answer.push_back(num);
                    dq.pop_back();
                }
            } else if (s == "size") {
                answer.push_back(dq.size());
            } else if (s == "empty") {
                answer.push_back(dq.empty());
            } else if (s == "front") {
                if (dq.empty()) {
                    answer.push_back(-1);
                } else {
                    answer.push_back(dq.front());
                }
            } else if (s == "back") {
                if (dq.empty()) {
                    answer.push_back(-1);
                } else {
                    answer.push_back(dq.back());
                }
            }
        }
    }
    
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << '\n';
    }
}