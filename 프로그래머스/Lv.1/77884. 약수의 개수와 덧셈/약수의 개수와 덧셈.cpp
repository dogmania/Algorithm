#include <bits/stdc++.h>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    int s = 0;
    
    for (int i = left; i <= right; i++) {
        s = static_cast<int>(sqrt(i));
        if (s * s == i) {
            answer -= i;
        } else answer += i;
    }
    
    return answer;
}