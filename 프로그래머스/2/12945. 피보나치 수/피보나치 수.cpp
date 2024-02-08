#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    vector<int> v;
    int i;
    v.push_back(0);
    v.push_back(1);
    
    while(1) {
        if (v.size() == n + 1) break;
        i = v.size() - 1;
        v.push_back((v[i] + v[i - 1]) % 1234567);
    }
    
    return v[n] % 1234567;
}