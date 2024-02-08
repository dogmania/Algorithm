#include <bits/stdc++.h>

using namespace std;

int maxSize(vector<vector<int>>&);

int solution(vector<vector<int>> sizes) {
    int w = sizes[0][0], h = sizes[0][1];
    int temp = 0;
    int result1 = 0;
    int result2 = 0;
    
    result1 = maxSize(sizes);
    
    for (auto& v: sizes) {
        if (v[1] > v[0]) {
            temp = v[1];
            v[1] = v[0];
            v[0] = temp;
        }
    }
    
    result2 = maxSize(sizes);
    
    return result1 < result2 ? result1 : result2;
}

int maxSize(vector<vector<int>>& s) {
    int w = s[0][0];
    int h = s[0][1];
    
    for (auto& v: s) {
        if (v[0] > w) w = v[0];
        if (v[1] > h) h = v[1];
    }
    
    return w * h;
}