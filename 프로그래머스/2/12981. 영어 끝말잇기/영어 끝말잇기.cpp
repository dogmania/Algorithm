#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    for (int i = 1; i < words.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (words[i] == words[j]) {
                answer.push_back(i % n + 1);
                answer.push_back(i / n + 1);
                break;
            }
            if (words[j][words[j].length() - 1] != words[j + 1][0]) {
                answer.push_back(i % n + 1);
                answer.push_back(i / n + 1);
                break;
            }
        }
        if (!answer.empty()) break;
    }
    
    if (answer.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}