#include <bits/stdc++.h>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int i;
    
    while (section.size() != 0) {
        i = section[0];
        for (int j = 0; j < section.size();) {
            if (section[0] >= i && section[0] < i + m) {
                section.erase(section.begin());
            } else break;
        }
        answer++;
        
        
    }
    
    return answer;
}