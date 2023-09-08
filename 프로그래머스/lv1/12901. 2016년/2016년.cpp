#include <bits/stdc++.h>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    map<int, int> m = { {1, 31}, {2, 29}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31} };
    int sum = 0;
    
    for (int i = 1; i < a; i++) {
        sum += m[i];
    }
    sum += b - 1;
    
    switch(sum % 7) {
        case 0:
            answer = "FRI";
            break;
        case 1: 
            answer = "SAT";
            break;
        case 2:
            answer = "SUN";
            break;
        case 3:
            answer = "MON";
            break;
        case 4: 
            answer = "TUE";
            break;
        case 5:
            answer = "WED";
            break;
        case 6:
            answer = "THU";
            break;
    }
    
    return answer;
}