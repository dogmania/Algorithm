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

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    vector<string> answer;
    int first = 1;
    int last = 2;
    
    cin >> s;

    while(first < last) {
        string s1 = s.substr(0, first);
        string s2 = s.substr(first, last - first);
        string s3 = s.substr(last);

        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        reverse(s3.begin(), s3.end());

        answer.push_back(s1 + s2 + s3);

        last++;

        if (last == s.length()) {
            first++;
            last = first + 1;

            if (first == s.length() - 1) break;
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer[0] << '\n';
}