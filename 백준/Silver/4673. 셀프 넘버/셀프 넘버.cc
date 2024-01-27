#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int num = 0;
    vector<int> v;
    string s;
    int firstIndex = 0;
    int lastIndex = 1;
    
    for (int i = 0; i < 10000; i++) {
        s = to_string(i);
        num += i;
        
        switch (s.length()) {
            case 1:
                num += s[0] - '0';
                break;
            case 2:
                num += (s[0] - '0') + (s[1] - '0');
                break;
            case 3:
                num += (s[0] - '0') + (s[1] - '0') + (s[2] - '0');
                break;
            case 4:
                num += (s[0] - '0') + (s[1] - '0') + (s[2] - '0') + (s[3] - '0');
                break;
            default:
                break;
        }
        
        if (num <= 10000) v.push_back(num);
        num = 0;
    }
    
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    while(lastIndex < v.size()) {
        for (int i = v[firstIndex] + 1; i < v[lastIndex]; i++) {
            cout << i << endl;
        }
        lastIndex++;
        firstIndex++;
    }
}
