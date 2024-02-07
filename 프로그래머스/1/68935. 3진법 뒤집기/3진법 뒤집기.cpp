#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    int num = 0;
    
    while(n >= 3) {
        v.push_back(n % 3);
        n /= 3;
    }
    v.push_back(n);
    
    for (int i = 0; i < v.size(); i++) {
        answer += pow(3, i) * v[v.size() - 1 - i];
    }
    
    return answer;
}