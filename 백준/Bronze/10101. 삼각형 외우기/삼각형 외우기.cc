#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <sstream>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <iterator>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c;

    cin >> a;
    cin >> b;
    cin >> c;

    if (a + b + c == 180) {
        if (a == b && b == c) cout << "Equilateral" << '\n';
        else if (a != b && b != c && c != a) cout << "Scalene" << '\n';
        else cout << "Isosceles" << '\n';
    } else {
        cout << "Error" << '\n';
    }
}