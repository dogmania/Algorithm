#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> array, int height) {
    int answer = 0;
    
    for(auto& a: array) {
        if (a > height) answer++;
    }
    
    return answer;
}