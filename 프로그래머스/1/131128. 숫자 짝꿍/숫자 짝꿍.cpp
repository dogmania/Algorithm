#include <bits/stdc++.h>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int a[10] = {0};
    int b[10] = {0};
    map<char, int>m = {
        {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}
    };
    int min = 0;
    
    for (int i = 0; i < X.length(); i++) {
        a[m[X[i]]]++;
    }
    
    for (int i = 0; i < Y.length(); i++) {
        b[m[Y[i]]]++;
    }
    
    for (int i = 9; i >= 0; i--) {
        if (a[i] >= b[i]) min = b[i];
        else min = a[i];
        for (int j = 0; j < min; j++) {
            answer += i + '0';
        }
    }
    
    if (answer == "") answer = "-1";
    if (answer[0] == '0') answer = "0";
    
    return answer;
}