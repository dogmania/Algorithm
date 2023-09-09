#include <bits/stdc++.h>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (auto& c: s) {
        if (c + n <= 90 && c >= 65 || c + n <= 122 && c >= 97) answer.push_back(c + n);
        else if (c + n >= 91 || c + n >= 123) {
            answer.push_back(c + n - 26);
        } else if (c == ' ') answer.push_back(' ');
    }
    
    return answer;
}