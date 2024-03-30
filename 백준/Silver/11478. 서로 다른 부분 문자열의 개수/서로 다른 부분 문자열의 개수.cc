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
    
    string s;
    map<string, int> answer;
    int length = 1;
    cin >> s;


    while(1) {
        for (int i = 0; i <= s.length() - length; i++) {
            string s1 = s.substr(i, length);
            answer[s1] = 1;
        }

        if (length == s.length()) break;
        else length++;
    }

    cout << answer.size() << '\n';
}