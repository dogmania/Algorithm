#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> num;
    
    if (n == 1) {
        num.push_back(1);
    } else {
        for (int i = 1; i < (n / 2); i++) {
            if (n % i == 0) {
                if (i * i == n) num.push_back(i);
                else if (i * i != n && find(num.begin(), num.end(), i) == num.end() && find(num.begin(), num.end(), n / i) == num.end()) {
                    num.push_back(i);
                    num.push_back(n / i);
                }
            }
        }
    }
    
    for (int i = 0; i < num.size(); i++) {
        answer += num[i];
    }
    
    return answer;
}