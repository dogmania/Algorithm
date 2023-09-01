#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    vector<string> v;
    
    for (int i = 0; i < goal.size();i++) {
        if (find(cards1.begin(), cards1.end(), goal[i]) != cards1.end()) {
            v.push_back(cards1[0]);
            cards1.erase(cards1.begin());
        } else if (find(cards2.begin(), cards2.end(), goal[i]) != cards2.end()) {
            v.push_back(cards2[0]);
            cards2.erase(cards2.begin());
        }
    }
    
    if (goal == v) answer = "Yes";
    else answer = "No";
    
    return answer;
}