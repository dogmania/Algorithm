#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int length;
    cin >> length;
    string s;
    cin >> s;
    string answer = "NO";
    int count = 0;
    
    for (int i = 0; i < length - 1; i++) {
        if (s[i + 1] - s[i] == -1 || s[i + 1] - s[i] == 1) count++;
        else count = 0;
        
        if (count == 4) {
            answer = "YES";
            break;
        }
    }
    
    cout << answer << endl;
}
