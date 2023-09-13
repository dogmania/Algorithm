#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int x_min = 9999;
    int x_max = -1;
    int y_min = 9999;
    int y_max = -1;
    
    for (int i = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[i].length(); j++) {
            if (wallpaper[i][j] == '#') {
                if (j < x_min) x_min = j;
                if (j + 1 > x_max) x_max = j + 1;
                if (i < y_min) y_min = i;
                if (i + 1 > y_max) y_max = i + 1;
            }
        }
    }  
    
    answer.push_back(y_min);
    answer.push_back(x_min);
    answer.push_back(y_max);
    answer.push_back(x_max);
    
    return answer;
}