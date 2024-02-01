#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main () {
    int w, k;
    cin >> w >> k;
    vector<string> v;
    string s1;
    string s2;
    string flag;
    string answer = "";
    vector<string> s;
    
    for (int i = 0; i < k * 2; i++) {
        cin >> s1;
        v.push_back(s1);
    }
    
    cin >> flag;
    
    for (int i = 0; i < k; i++) {
        s1 = v[i];
        s2 = v[i + k];
        
        for (int j = 0; j < w; j++) {
            if (s1[j] == '1' && s2[j] == '1') answer.push_back(flag[3]);
            else if (s1[j] == '0' && s2[j] == '0') answer.push_back(flag[0]);
            else if (s1[j] == '0' && s2[j] == '1') answer.push_back(flag[1]);
            else answer.push_back(flag[2]);
        }
        
        s.push_back(answer);
        answer = "";
    }
    
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << endl;
    }
}
