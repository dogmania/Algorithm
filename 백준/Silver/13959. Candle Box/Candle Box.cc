#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n;
    int r, t;
    cin >> n;
    cin >> r;
    cin >> t;
    int x = 3;
    int y = 4;
    int sum = x + y;
    int i = 0;
    int answer = 0;
    
    for (int i = 1; i < n; i++) {
        y++;
        sum += y;
    }
    
    while (r + t != sum) {
        x++;
        y++;
        sum += (x + y);
    }
    
    for (int i = 4; i <= y; i++) {
        answer += i;
    }
    
    cout << r - answer << endl;
}
