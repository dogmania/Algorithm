#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    string ss = "";
    
    for (int i = 0; i < s.length();) {
        if (s[i] >= 97 && s[i] <= 122) {
            switch(s[i]) {
                case 'z':
                    ss.push_back('0');
                    i += 4;
                    break;
                case 'o':
                    ss.push_back('1');
                    i += 3;
                    break;
                case 't':
                    if (s[i + 1] == 'w') {
                        ss.push_back('2');
                        i += 3;
                    }
                    else {
                        ss.push_back('3');
                        i += 5;
                    }
                    break;
                case 'f':
                    if (s[i + 1] == 'o') ss.push_back('4');
                    else ss.push_back('5');
                    i += 4;
                    break;
                case 's':
                    if (s[i + 1] == 'i') {
                        ss.push_back('6');
                        i += 3;
                    }
                    else {
                        ss.push_back('7');
                        i += 5;
                    }
                    break;
                case 'e':
                    ss.push_back('8');
                    i += 5;
                    break;
                default:
                    ss.push_back('9');
                    i += 4;
                    break;
            }
        } else {
            ss.push_back(s[i]);
            i++;
        }
    }
    
    return stoi(ss);
}