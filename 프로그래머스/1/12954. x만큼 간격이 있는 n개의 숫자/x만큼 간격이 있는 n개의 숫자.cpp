#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    
    for (int i = 0; i < n; i++) {
        answer.push_back(x + x * i);
    }
    
    return answer;
}