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

int devide(int n) {
    int count = 0;

    while (1) {
        if (n / 10 == 0) break;

        n /= 10;
        count++;
    }

    return count;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    long long answer = 0;
    cin >> n;
    int count = devide(n);

    if (count != 0) {
        for (int i = 0; i < count; i++) {
            answer += 9 * pow(10, i) * (i + 1);
        }
        answer += (n - pow(10, count) + 1) * (count + 1);
    } else {
        answer = n;
    }

    cout << answer << '\n';
}