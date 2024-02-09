#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for (int i = 1;; i++) {
        for (int j = i;; j++) {
            if ((i + 2) * (j + 2) > brown + yellow) break;
            if (i * j > yellow) break;
            else if (i * j == yellow && (i + 2) * (j + 2) == brown + yellow) {
                answer.push_back(j + 2);
                answer.push_back(i + 2);
            }
        }
        if (!answer.empty()) break;
    }
    
    return answer;
}