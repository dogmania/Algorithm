#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    string s1;
    vector<int> v;
    
    while (ss >> s1) {
        v.push_back(stoi(s1));
    }
    
    sort(v.begin(), v.end());
    
    answer = to_string(v.front()) + ' ' + to_string(v.back());
    
    return answer;
}