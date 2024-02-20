#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    vector<int> num(4);
    bool p;
    int i = 1;
    
    sort(arr.begin(), arr.end());
    
    while (1) {
        p = true;
        answer = arr.back() * i;
        
        for (int i = 0; i < arr.size(); i++) {
            if (answer % arr[i] != 0) {
                p = false;
                break;
            }
        }
        
        if (p) break;
        i++;
    }
    
    return answer;
}