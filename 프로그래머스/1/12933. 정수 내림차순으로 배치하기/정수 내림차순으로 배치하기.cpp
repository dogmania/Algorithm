#include <bits/stdc++.h>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string input = to_string(n);
    
    sort(input.rbegin(), input.rend());
    answer = stoll(input);
    
    return answer;
}