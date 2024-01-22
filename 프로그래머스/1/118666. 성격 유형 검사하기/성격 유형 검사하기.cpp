#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int>m = {
        {'R', 0}, {'T', 0}, {'C', 0}, {'F', 0}, {'J', 0}, {'M', 0}, {'A', 0}, {'N', 0}
    };
    int choice = -1;
    char alphabet;
    int score = 0;
    
    for (int i = 0; i < survey.size(); i++) {
        if (choices[i] != 4) {
            choice = choices[i];
            alphabet = survey[i][choice / 4];
            if (choice > 4) {
                m[alphabet] += (choice % 4);
            } else if (choice == 3) m[alphabet] += 1;
            else if (choice == 2) m[alphabet] += 2;
            else m[alphabet] += 3;
        }
    }
    
    if (m['R'] >= m['T']) answer += 'R';
    else answer += 'T';
    if (m['C'] >= m['F']) answer += 'C';
    else answer += 'F';
    if (m['J'] >= m['M']) answer += 'J';
    else answer += 'M';
    if (m['A'] >= m['N']) answer += 'A';
    else answer += 'N';
    
    return answer;
}