#include <bits/stdc++.h>

using namespace std;

bool cmp(string s1, string s2);
int N = 0;

vector<string> solution(vector<string> strings, int n) {
    N = n;
    
    sort(strings.begin(), strings.end(), cmp);
    
    return strings;
}

bool cmp(string s1, string s2) {
    if (s1[N] == s2[N]) return s1 <= s2;
    else return s1[N] <= s2[N];
}