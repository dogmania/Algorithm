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
    
    int m;
    cin >> m;
    vector<int> answer;

    for (int i = 0; i < m; i++) {
        int n, index;
        int count = 1;
        cin >> n >> index;
        deque<int> importance;

        string s, s1;
        cin.ignore();
        getline(cin, s);
        stringstream ss(s);

        while (ss >> s1) {
            importance.push_back(s1[0] - '0');
        }

        while (1) {
            int max = *max_element(importance.begin(), importance.end());

            while(importance.front() != max) {
                importance.push_back(importance.front());
                importance.pop_front();
                if (index > 0) index--;
                else if (index == 0) {
                    index = importance.size() - 1;
                }
            }

            if (index == 0) break;

            importance.pop_front();
            index--;
            count++;

            if (importance.empty()) break;
        }

        answer.push_back(count);
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << '\n';
    }
}