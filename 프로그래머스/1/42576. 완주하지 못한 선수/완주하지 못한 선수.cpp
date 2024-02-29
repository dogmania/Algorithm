#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m1;
    map<string, int> m2;
    
    for (auto p: participant) {
        m1[p]++;
    }
    
    for (auto c: completion) {
        m2[c]++;
    }
    
    auto i = m1.begin();
    auto j = m2.begin();
    while (1) {
        if (i->first != j->first || i->second != j->second) {
            answer = i->first;
            break;
        }
        i++;
        j++;
    }
    
    return answer;
}