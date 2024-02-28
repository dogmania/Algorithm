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
    
    int n;
    deque<int> q;
    cin >> n;

    cin.ignore();

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        if (s.length() >= 6) {
            stringstream ss(s);
            string s1;
            int num;
            ss >> s1 >> num;
            q.push_back(num);
        } else {
            if (s.compare("pop") == 0) {
                if (!q.empty()) {
                    cout << q.front() << '\n';
                    q.pop_front();
                } else {
                    cout << -1 << '\n';
                }
            } else if (s.compare("size") == 0) {
                cout << q.size() << '\n';
            } else if (s.compare("empty") == 0) {
                cout << q.empty() << '\n';
            } else if (s.compare("front") == 0) {
                if (!q.empty()) {
                    cout << q.front() << '\n';
                } else {
                    cout << -1 << '\n';
                }
            } else if (s.compare("back") == 0) {
                if (!q.empty()) {
                    cout << q.back() << '\n';
                } else {
                    cout << -1 << '\n';
                }
            }
        }
    }
}