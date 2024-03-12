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
    
    int num;
    cin >> num;
    int answer = 1;
    int first = 2;
    int flag = 5;

    while (num != 1) {
        answer++;

        if (num >= first && num <= (first + flag)) break;

        first += flag + 1;
        flag += 6;
    }

    cout << answer << '\n';
}