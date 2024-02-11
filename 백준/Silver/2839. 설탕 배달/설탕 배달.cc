#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <sstream>

using namespace std;

int main(void) {
    int n, n1;
    cin >> n;
    n1 = n;
    int count = 0;

    while (n >= 5) {
        n -= 5;
        count++;
    }
    
    while (n != 0) {
        if (n % 3 != 0) {
            n += 5;
            count--;
        } else {
            count += n / 3;
            n = 0;
        }
        
        if (n > n1) {
            count = -1;
            break;
        }
    }
    
    cout << count << endl;
}