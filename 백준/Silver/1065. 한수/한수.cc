#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <sstream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    int answer = 0;
    int first = 0;
    int second = 0;
    int third = 0;
    
    for (int i = 1; i <= n; i++) {
        if (i / 10 <= 9) answer++;
        else {
            first = i / 100;
            third = i % 10;
            second = (i - first * 100) / 10;
            
            if (first - second == second - third) answer++;
        }
    }
    
    cout << answer << endl;
}