#include <bits/stdc++.h>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    int q = 0;
    int count = 0;
    
    for (int i = 1; i <= number; i++) {
        count = 0;
        for (int j = 1; j <= (i / 2); j++) {
            q = i / j;
            if (q == j && q * j == i) {
                count++;
            } else if (q != j && q > j && q * j == i) {
                count += 2;
            }
        }
        if (count > limit) answer += power;
        else answer += count;
    }
        
    return answer + 1;
}