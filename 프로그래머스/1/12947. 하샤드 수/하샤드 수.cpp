#include <bits/stdc++.h>

using namespace std;

bool solution(int x) {
    string input = to_string(x);
    int sum = 0;
    
    for (int i = 0; i < input.length(); i++) {
        sum += input[i] - '0';
    }
    
    return x % sum == 0 ? true : false;
}