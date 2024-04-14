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
    
    int n, m;
    vector<int> pos;
    string s;
    int index = 0;
    int answer = 1;

    cin >> n >> m;
    cin.ignore();
    getline(cin, s);

    stringstream ss(s);
    string s1;

    while (ss >> s1) {
        pos.push_back(stoi(s1));
    }

    sort(pos.begin(), pos.end());

    while(1) {

        for (int i = index + 1; i < n; i++) {

            if(pos[index] - 0.5 + m >= pos[i] + 0.5) {
                if (i == n - 1) index = i;
                else continue;
            }
            else {
                answer++;
                index = i;
                break;
            }

            
        }

        if (index == n - 1) break;
    }

    cout << answer << '\n';
}